// This program use an AVL Tree to store an Ordered Dictionary
// The Dictionary contains functions to add, delete, and search words
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct Node {
    string key;
    string definition;
    int height;
    Node *left;
    Node *right;

    Node(string key, string definition) {
        this->key = key;
        this->definition = definition;
        this->height = 1;
        left = NULL;
        right = NULL;
    }
};

Node* createNode(string key, string definition) {
    Node* newNode = new Node(key, definition);
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

Node* insertWord(Node* node, string key, string definition) {
    if (!node) return createNode(key, definition);

    if (key < node->key)  
        node->left = insertWord(node->left, key, definition);  
    else if (key > node->key)  
        node->right = insertWord(node->right, key, definition);  
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

Node* deleteWord(Node* node, string key) {
    if (!node) return node;

    if (key < node->key) node->left = deleteWord(node->left, key);
    else {
        if (key > node->key) node->right = deleteWord(node->right, key);
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
                node->right = deleteWord(node->right, temp->key);
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

void searchWord(Node* cur, string key) {
    if (!cur) {
        cout << "The word you are looking for not in the dictionary" << endl;
        return;
    }

    if (key < cur->key) searchWord(cur->left, key);
    else {
        if (key > cur->key) searchWord(cur->right, key);
        else {
            cout << "Word: " << cur->key << "- Definition: " << cur->definition << endl;
            return;
        }
    }
}

void printDictionary(Node* cur) {
    if (!cur) return;
    printDictionary(cur->left);
    cout << "Word: " << cur->key << " - Definition: " << cur->definition << " - Height: " << cur->height << endl;
    printDictionary(cur->right);
}


int main() {
    cout << "This program use an AVL Tree to store an Ordered Dictionary. \nThe Dictionary contains functions to add, delete, and search words." << endl;
    Node* root = NULL;
    root = insertWord(root, "Buffalo", "Yellow");
    root = insertWord(root, "Elephant", "Gray");
    root = insertWord(root, "Fish", "Blue");
    root = insertWord(root, "Parrot", "Green");
    root = insertWord(root, "Shark", "Cyan");
    printDictionary(root);
    cout << endl;
    cout << "Delete the Parrot word" << endl;
    root = deleteWord(root, "Parrot");
    printDictionary(root);
    cout << endl;
    cout << "Search for Fish" << endl;
    searchWord(root, "Fish");
    cout << endl;
    cout << "Search for Frog" << endl;
    searchWord(root, "Frog");
    return 0;
}