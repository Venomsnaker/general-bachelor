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
    double avg;
};

struct Node {
    Student data;
    Node* pLeft;
    Node* pRight;
    int height;

    Node(Student newData) {
        this->data = newData;
        pLeft = NULL;
        pRight = NULL;
        height = 1;
    }
};

Node* createNode(Student data) {
    Node* newNode = new Node(data);
    return newNode;
}

int getNodeHeight(Node* node) {
    if (!node) return 0;
    else return node->height;
}

void updateNodeHeight(Node*& node) {
    node->height = max(getNodeHeight(node->pLeft), getNodeHeight(node->pRight)) + 1;
}

int getBalance(Node* node) {
    if (!node) return 0;
    return getNodeHeight(node->pLeft) - getNodeHeight(node->pRight);
}
Node* rotateRight(Node* y) {
    Node* x = y->pLeft;
    Node* z = x->pRight;

    x->pRight = y;
    y->pLeft = z;

    updateNodeHeight(y);
    updateNodeHeight(x);
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->pRight;
    Node* z = y->pLeft;

    y->pLeft = x;
    x->pRight = z;

    updateNodeHeight(x);
    updateNodeHeight(y);
    return y;
}

Node* balanceNode(Node* node) {
    updateNodeHeight(node);
    int balance = getBalance(node);

    // L L
    if (balance > 1 && node->data.code < node->pLeft->data.code) {
        return rotateRight(node);
    }

    // R R
    if (balance < -1 && node->data.code > node->pRight->data.code) {
        return rotateLeft(node);
    }

    // L R
    if (balance > 1 && node->data.code > node->pLeft->data.code) {
        node->pLeft = rotateLeft(node->pLeft);
        return rotateRight(node);
    }

    // R L
    if (balance < -1 && node->data.code < node->pRight->data.code) {
        node->pRight = rotateRight(node->pRight);
        return rotateLeft(node);
    }
    return node;
}

string gradeStudent(int avg) {
    if (avg < 5) return "'Yeu'";
    if (avg >= 5 && avg < 7) return "'TrungBinh'";
    if (avg >= 7 && avg < 8) return "'Kha'";
    if (avg >= 8) return "'Gioi'";
    return "Unknown";
}

Node* insertNode(Node* node, Student st) {
    if (!node) return createNode(st);

    if (st.code < node->data.code) node->pLeft = insertNode(node->pLeft, st);
    else {
        if (st.code > node->data.code) {
            node->pRight = insertNode(node->pRight, st);
        }
        else {
            // No Duplication Allowed
            return node;
        }
    }
    return balanceNode(node);
}

Student inputCustomStudent() {
    string code, name;
    float score_theory, score_practice;

    cout << "Input a student: " << endl;

    cout << "Input MSSV: ";
    do {
        cin >> code;
    } while (code.size() != 8);
    cin.ignore();

    cout << "Input Ho va Ten: ";
    getline(cin, name);

    cout << "Input Diem LT: ";
    cin >> score_theory;

    cout << "Input Diem TH: ";
    cin >> score_practice;
    Student st;
    st.code = code;
    st.name = name;
    st.score_theory = score_theory;
    st.score_practice = score_practice;
    st.avg = double(0.7 * score_theory + 0.3 * score_practice);
    return st;
}

void writeFile(string filePath, Node* root) {
    cout << "Students with avg == 'Trung Binh'" << endl;
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
                    if (gradeStudent(temp->data.avg) == "'TrungBinh'") {
                        outfile << temp->data.code << endl;
                        cout << temp->data.code << endl;
                    }
                    q.push(temp->pLeft);
                    q.push(temp->pRight);
                }
            }
        }
        outfile.close();
    }
    return;
}

void printTree(Node* cur) {
    if (!cur) return;
    printTree(cur->pLeft);
    cout << cur->data.code << " " << cur->data.name << " " << cur->data.score_theory << " " << cur->data.score_practice << " " << cur->data.avg << " " << gradeStudent(cur->data.avg) << endl;
    printTree(cur->pRight);
}

int main()
{
    cout << "\t Kiem tra thuc hanh DSA cuoi ki - 22TNT1" << endl;
    cout << "\t 22120128 - Bui Quoc Huy" << endl;
    Node* root = NULL;
    Student st6 = inputCustomStudent();
    root = insertNode(root, st6);
    Student st1, st2, st3, st4, st5;

    st1.code = "12055100";
    st1.name = "Ly Ngoc Lan";
    st1.score_theory = 6.5;
    st1.score_practice = 6.5;
    st1.avg = double(0.7 * st1.score_theory + 0.3 * st1.score_practice);


    st2.code = "12055110";
    st2.name = "Le Van An";
    st2.score_theory = 9.1;
    st2.score_practice = 9.1;
    st2.avg = double(0.7 * st2.score_theory + 0.3 * st2.score_practice);

    st3.code = "12055120";
    st3.name = "Tran Van Tung";
    st3.score_theory = 6;
    st3.score_practice = 6;
    st3.avg = double(0.7 * st3.score_theory + 0.3 * st3.score_practice);

    st4.code = "12055130";
    st4.name = "Mai Chi Thanh";
    st4.score_theory = 9.5;
    st4.score_practice = 9.5;
    st4.avg = double(0.7 * st4.score_theory + 0.3 * st4.score_practice);

    st5.code = "12055150";
    st5.name = "Ly Nhan Tong";
    st5.score_theory = 8.9;
    st5.score_practice = 8.9;
    st5.avg = double(0.7 * st5.score_theory + 0.3 * st5.score_practice);

    root = insertNode(root, st1);
    root = insertNode(root, st2);
    root = insertNode(root, st3);
    root = insertNode(root, st4);
    root = insertNode(root, st5);
    printTree(root);

    writeFile("ds_SVTB.txt", root);
    return 0;
}
