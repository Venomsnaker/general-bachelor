#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

struct Student
{
    string code;
    string name;
    float score_theory;
    float score_practice;
    float avg;
};

struct Node
{
    Student student;
    Node* left;
    Node* right;
    int height;

    Node(Student student) {
        this->student = student;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

Node* createNode(Student student) {
    Node* newNode = new Node(student);
    return newNode;
}

int getNodeHeight(Node *node) {
    if (!node) return 0;
    else return node->height;
}

void updateNodeHeight(Node *&node) {
    node->height = max(getNodeHeight(node->left), getNodeHeight(node->right)) + 1;
}

int getBalance(Node *node) {
    if (!node) return 0;
    return getNodeHeight(node->left) - getNodeHeight(node->right);
}

Node* rotateRight(Node *y) {
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    updateNodeHeight(y);
    updateNodeHeight(x);
    return x;
}

Node* rotateLeft(Node *x) {
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    updateNodeHeight(x);
    updateNodeHeight(y);
    return y;
}

Node* minValueNode(Node *node) {
    Node *cur = node;
    while (cur->left) cur = cur->left;
    return cur;
}

Node* balanceNode(Node* node) {
    updateNodeHeight(node);
    int balance = getBalance(node);

    // Left Left Case  
    if (balance > 1 && node->student.code < node->left->student.code)  
        return rotateRight(node);  

    // Right Right Case  
    if (balance < -1 && node->student.code > node->right->student.code)  
        return rotateLeft(node);  

    // Left Right Case  
    if (balance > 1 && node->student.code > node->left->student.code)  
    {  
        node->left = rotateLeft(node->left);  
        return rotateRight(node);  
    }  

    // Right Left Case  
    if (balance < -1 && node->student.code < node->right->student.code)  
    {  
        node->right = rotateRight(node->right);  
        return rotateLeft(node);  
    } 

    return node;
}

Node* insertNode(Node* node, Student student) {
    if (!node) return createNode(student);

    if (student.code < node->student.code)  
        node->left = insertNode(node->left, student);  
    else if (student.code > node->student.code)  
        node->right = insertNode(node->right, student);  
    else
        return node;  
    return balanceNode(node);
}

Node* deleteNode(Node* node, Student student) {
    if (!node) return node;

    if (student.code < node->student.code) node->left = deleteNode(node->left, student);
    else {
        if (student.code > node->student.code) node->right = deleteNode(node->right, student);
        else {
            if (node->left == NULL || node->right == NULL) {
            Node *temp = node->left ? node->left : node -> right;

            // No Child
            if (temp == NULL) { 
                temp = node;
                node = NULL;
            } else {
                // One Child 
                *node =*temp;
                free(temp);
            } 
            } else {
                // Two Children Case
                Node* temp = minValueNode(node->right);
                node->student = temp->student;
                node->right = deleteNode(node->right, temp->student);
            }
        }
        if (!node) return node;

        return balanceNode(node);
    }
    return node;
}

void inputCustomNode(Node* root) {
    string code, name;
    float score_theory, score_practice;

    cout << "Input code (length = 8): ";
    do {
        cin >> code;
    } while (code.size() != 8);
    cin.ignore();
    cout << "Input name: "; 
    getline(cin, name);
    cout << "Input theory score: ";
    cin >> score_theory;
    cout << "Input practice score: ";
    cin >> score_practice;
    Student st;
    st.code = code;
    st.name = name;
    st.score_practice = score_practice;
    st.score_theory = score_theory;
    st.avg = 0;
    insertNode(root, st);
}

void printTree(Node* cur) {
    if (!cur) return;
    printTree(cur->left);
    cout << cur->student.code << " " << cur->student.name << " " << cur->student.score_theory << " " << cur->student.score_practice << endl;
    printTree(cur->right);
}

void readFile(string filePath, Node** root) {
    fstream infile(filePath);

    if (infile.is_open()) {
        string line;
        while(getline(infile, line)) {
            Student student;
            student.code = line.substr(0, 8);
            student.name = line.substr(9, line.size() - 18);
            student.score_theory = stof(line.substr(line.size() - 8, 3));
            student.score_practice = stof(line.substr(line.size() - 3, 3));
            student.avg = (student.score_theory + student.score_practice) / 2;
            *root = insertNode(*root, student);
        }
        infile.close();
    }
}

void writeFile(string filePath, Node* root) {
    ofstream outfile(filePath);

    if (outfile.is_open()) {
        if (!root) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int qSize = q.size();

            for (int _ = 0; _ < q.size(); _++) {
                Node* temp = q.front();
                q.pop();

                if (temp) {
                    outfile  << temp->student.code << " " << temp->student.name << " " << fixed << setprecision(1) << temp->student.score_theory << " " << temp->student.score_practice << endl;
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
        }
    }
    outfile.close();
    return;
}

bool checkAVLRecursive(Node* node) {
    if (!node) return true;

    int k = abs(getNodeHeight(node->left) - getNodeHeight(node->right));
    if (k > 1) return false;
    return checkAVLRecursive(node->left) && checkAVLRecursive(node->right);
}

bool checkAVLIterative(Node* node) {
    if (!node) return true;

    queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        int qSize = q.size();

        while (qSize > 0) {
            Node* cur = q.front();
            int l = getNodeHeight(cur->left);
            int r = getNodeHeight(cur->right);

            if (abs(r - l) > 1) return false;
            q.pop();

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
            qSize--;
        }
    }
    return true;
}

int main() {
    Node* root = NULL;
    readFile("sample.txt", &root);
    Student to_be_added_1;
    to_be_added_1.code = "22120128";
    to_be_added_1.name = "Huy Bui";
    to_be_added_1.score_theory = 8.7;
    to_be_added_1.score_practice = 8.8;
    root = insertNode(root, to_be_added_1);
    Student to_be_deleted_1;
    to_be_deleted_1.code = "12055130";
    deleteNode(root, to_be_deleted_1);
    inputCustomNode(root);
    printTree(root);
    writeFile("output.txt", root);
    return 0;
}
