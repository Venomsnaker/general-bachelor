#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* createNode(int data) {
    Node* nodeNew = new Node(data);
    return nodeNew;
}

void insertNode(Node*& cur, int data) {
    if (!cur) {
        cur = createNode(data);
        return;
    }

    if (cur->data > data) insertNode(cur->left, data);
    else insertNode(cur->right, data);
}

void traverseInorder(Node* cur) {
    if (!cur) return;

    traverseInorder(cur->left);
    cout << cur->data << " ";
    traverseInorder(cur->right);
}

void traverseLevelOrder(Node* cur) {
    if (!cur) return;
    cout << "Duyet cay theo tung tang: " << endl;

    queue<Node*> q;
    q.push(cur);

    while(!q.empty()) {
        int qSize = q.size();

        for (int i = 0; i < qSize; i++) {
            Node* temp = q.front();
            q.pop();

            if (temp) {
                cout << temp->data << " ";
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}

int countLeafNodes(Node* cur) {
    if (cur == NULL) return 0;
    if (cur->left == NULL && cur->right == NULL) {
        return 1;
    }
    return countLeafNodes(cur->left) + countLeafNodes(cur->right);
}

int getNodeClosestToX(Node* cur, int x) {
    if (cur == NULL) return INT_MIN;
    int res = cur->data;

    while (cur != NULL) {
        if (abs(cur->data - x) < abs(res - x)) {
            res = cur->data;
        }

        if (cur->data < x) {
            cur = cur->right;
        }
        else {
            if (cur->data > x) {
                cur = cur->left;
            }
            else {
                return x;
            }
        }
    }
    return res;
}

void visualiseBST() {
    cout << "Tao mot cay nhi phan tim kiem bang cach them vao cay lan luot: 10, 15, 5, 17, 8, 13, 3" << endl;
    Node* root1 = createNode(10);
    const int n1 = 6;
    int nodeList1[n1] = { 15, 5, 17, 8, 13, 3 };
    for (int i = 0; i < n1; i++) {
        insertNode(root1, nodeList1[i]);
    }

    cout << "Kiem tra cay nhi phan tim kien bang cach duyen trung thu tu: ";
    traverseInorder(root1);
    cout << endl;

    traverseLevelOrder(root1);

    cout << "So node la trong cay BST da tao la: " << countLeafNodes(root1) << endl;
    cout << endl;

    cout << "Tao mot cay nhi phan tim kiem khac bang cach them vao cay lan luot: 10, 5, 15, 2" << endl;
    Node* root2 = createNode(10);
    const int n2 = 3;
    int nodeList2[n2] = { 5, 15, 2};
    for (int i = 0; i < n2;i++) {
        insertNode(root2, nodeList2[i]);
    }

    cout << "Kiem tra cay nhi phan tim kien bang cach duyen trung thu tu: ";
    traverseInorder(root2);
    cout << endl;

    traverseLevelOrder(root2);

    cout << "So node la trong cay BST da tao la: " << countLeafNodes(root2) << endl;

    int x1 = 8, x2 = 2, x3 = 20;
    cout << "O cay thu 2: " << endl;
    cout << "Gia tri node gan voi " << x1 << " nhat la: " << getNodeClosestToX(root2, x1) << endl;
    cout << "Gia tri node gan voi " << x2 << " nhat la: " << getNodeClosestToX(root2, x2) << endl;
    cout << "Gia tri node gan voi " << x3 << " nhat la: " << getNodeClosestToX(root2, x3) << endl;
    cout << endl;
}

int main()
{
    visualiseBST();
    return 0;
}