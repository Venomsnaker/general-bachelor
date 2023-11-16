#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int key;
    int height;
    Node *left;
    Node *right;

    Node(int key) {
        this->key = key;
        this->height = 1;
        left = NULL;
        right = NULL;
    }
};

Node* createNode(int key) {
    Node* newNode = new Node(key);
    return newNode;
}

int getNodeHeight(Node* node) {
    if (!node) return 0;
    else return node->height;
}

void updateNodeHeight(Node* &node) {
    node->height = max(getNodeHeight(node->left), getNodeHeight(node->right)) + 1;
}

int getBalance(Node* node) {
    if (!node) return 0;
    return getNodeHeight(node->left) - getNodeHeight(node->right);
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;

    x->right = y;
    y->left = t2;

    updateNodeHeight(y);
    updateNodeHeight(x);
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    updateNodeHeight(x);
    updateNodeHeight(y);
    return y;
}

Node* minValueNode(Node* node) {
    Node* cur = node;
    while (cur->left) cur = cur->left;
    return cur; 
}

Node* insertNode(Node* node, int key) {
    if (!node) return createNode(key);

    if (key < node->key)  
        node->left = insertNode(node->left, key);  
    else if (key > node->key)  
        node->right = insertNode(node->right, key);  
    else
        return node;  

    updateNodeHeight(node);
    int balance = getBalance(node);

    // Left Left Case  
    if (balance > 1 && key < node->left->key)  
        return rotateRight(node);  
  
    // Right Right Case  
    if (balance < -1 && key > node->right->key)  
        return rotateLeft(node);  
  
    // Left Right Case  
    if (balance > 1 && key > node->left->key)  
    {  
        node->left = rotateLeft(node->left);  
        return rotateRight(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && key < node->right->key)  
    {  
        node->right = rotateRight(node->right);  
        return rotateLeft(node);  
    } 
    return node;
}


Node* deleteNode(Node* node, int key) {
    if (!node) return node;

    if (key < node->key) node->left = deleteNode(node->left, key);
    else {
        if (key > node->key) node->right = deleteNode(node->right, key);
        else {
            if (node->left == NULL || node->right == NULL) {
                Node *temp = node->left ? node->left : node->right;

                // No Child Case
                if (temp == NULL) {
                    temp = node;
                    node = NULL;
                }
                else {
                    // One Child Case
                    *node = *temp;
                    free(temp);
                }
            } else {
                // Two Children Case
                Node* temp = minValueNode(node->right); 
                node->key = temp->key; 
                node->right = deleteNode(node->right, temp->key);
            }
        }
        if (!node) return node;
        updateNodeHeight(node);
        int balance = getBalance(node);
    }

    if (!node) return node;
    updateNodeHeight(node);
    int balance = getBalance(node);

    // Left Left Case  
    if (balance > 1 && key < node->left->key)  
        return rotateRight(node);  
  
    // Right Right Case  
    if (balance < -1 && key > node->right->key)  
        return rotateLeft(node);  
  
    // Left Right Case  
    if (balance > 1 && key > node->left->key)  
    {  
        node->left = rotateLeft(node->left);  
        return rotateRight(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && key < node->right->key)  
    {  
        node->right = rotateRight(node->right);  
        return rotateLeft(node);  
    } 
    return node;
}

void printTree(Node* cur) {
    if (!cur) return;
    printTree(cur->left);
    cout << "Node: " << cur->key << " - Height: " << cur->height << endl;
    printTree(cur->right);
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



int main()
{
    Node* root = NULL; 
    cout << "Insert into the tree in this order: 16, 15, 14, 9, 13, 19, 17. Then print in preorder position." << endl;
    root = insertNode(root, 16);  
    root = insertNode(root, 15);  
    root = insertNode(root, 14); 
    root = insertNode(root, 9);  
    root = insertNode(root, 13);  
    root = insertNode(root, 19);  
    root = insertNode(root, 16);  
    printTree(root);
    cout << "Is the tree an AVL: " << checkAVLIterative(root) << endl;
    cout << endl;
    cout << "Delete 15 and 17. Then print in preorder position." << endl;
    root = deleteNode(root, 15);
    root = deleteNode(root, 16);
    printTree(root);
    cout << "Is the tree an AVL: " << checkAVLRecursive(root) << endl;
    return 0;
}
