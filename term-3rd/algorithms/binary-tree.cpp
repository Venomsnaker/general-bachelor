#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;

    Node(int key) {
        this->key = key;
        left = NULL;
        right = NULL;
    }
};

Node* createNode(int key) {
    Node* newNode = new Node(key);
    return newNode;
}

void insertNode_BST(Node* &cur, int key) {
    if (!cur) {
        cur = createNode(key);
        return;
    }

    if (key > cur->key) insertNode_BST(cur->left, key);
    else insertNode_BST(cur->right, key); 
}

Node* deleteNode(Node* &cur, int key) {
    if (!cur) return NULL;
    
    if (cur->key > key) cur->left = deleteNode(cur->left, key);
    else {
        if(cur->key < key) cur->right = deleteNode(cur->right, key);
        else {
            if (cur->left == NULL) {
                Node* temp = cur->right;
                delete cur;
                return temp;
            }

            if (cur->right == NULL) {
                Node* temp = cur->left;
                delete cur;
                return temp;
            }
            else {
                Node* parent = cur;
                Node* succ = cur->right;

                while (succ->left != NULL) {
                    parent = succ;
                    succ = succ->left;
                }

                if (parent != cur) {
                    parent->left = succ->right;
                }
                else {
                    parent->right = succ->right;
                }

                cur->key = succ->key;
                delete succ;
            }           
        }
        return cur;
    }
}

void insertNode_levelOrder(Node* &cur, int key) {
    if (!cur) {
        cur = createNode(key);
        return;
    }

    queue<Node*> q;
    q.push(cur);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left != NULL) q.push(temp->left);
        else {
            temp->left = createNode(key);
            return;
        }

        if (temp->right != NULL) q.push(temp->right);
        else {
            temp->right = createNode(key);
            return;
        }
    }
}

bool searchBST(Node* cur, int key) {
    if (!cur) return 0;

    if (cur->key == key) return 1;

    if (cur->key > key) return searchBST(cur->left, key);
    else return searchBST(cur->right, key);
}

void printPreorder(Node* cur) {
    if (!cur) return;
    cout << cur->key << endl;
    printPreorder(cur->left);
    printPreorder(cur->right);
}

void printInorder(Node* cur) {
    if (!cur) return;
    printPreorder(cur->left);
    cout << cur->key << endl;
    printPreorder(cur->right);
}

void printPostorder(Node* cur) {
    if (!cur) return;
    printPreorder(cur->left);
    printPreorder(cur->right);
    cout << cur->key << endl;
}

void printLevelorder(Node* cur) {
    if (!cur) return;

    queue<Node*> q;
    q.push(cur);

    while (!q.empty()) {
        int qSize = q.size();
        
        for (int _ = 0; _ < qSize; _++) {
            Node* temp = q.front();
            q.pop();

            if (temp) {
                cout << temp->key << " " << endl;
                q.push(temp->left);
                q.push(temp->right);
            }
        }
    }
    return;
}

int main() {
    Node* root = createNode(1);
    insertNode_levelOrder(root, 2);
    insertNode_levelOrder(root, 3);
    insertNode_levelOrder(root, 4);
    printLevelorder(root);
}
