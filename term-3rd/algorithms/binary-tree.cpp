#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    int key;
    Node *left, *right;

    Node(int key) {
        this->key = key;
        left = NULL;
        right = NULL;
    }
};

Node* createNode(int key) {
    Node* n = new Node(key);
    return n;
}

int getDepth(Node* node) {
    if (node == NULL) return 0;
    else {
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        if (leftDepth > rightDepth) {
            return (leftDepth + 1);
        } else {
            return (rightDepth + 1);
        }
    }
}

void insertNode_BS(Node* &cur, int key) {
    if (!cur) {
        cur = createNode(key);
        return;
    }

    if (cur->key > key) insertNode_BS(cur->left, key);
    else insertNode_BS(cur->right, key);
}

void insertNode_BS_NoRecursion(Node* &root, int key) {
    Node* prev = NULL;
    Node* cur = root;

    if (!root) {
        root = createNode(key);
        return;
    }

    while (cur != NULL) {
        prev = cur;
        if (key < cur->key) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    if (key < prev->key) {
        prev->left = createNode(key);
    } else prev->right = createNode(key);
}

bool searchNode_BS(Node* cur, int key) {
    if (!cur) return false;
    if (cur->key == key) return true;

    if (cur->key < key) return searchNode_BS(cur->left, key);
    else return searchNode_BS(cur->right, key);
}

Node* deleteNode_BS(Node* &cur, int key) {
    if (!cur) return NULL;

    if (cur->key > key) cur->left = deleteNode_BS(cur->left, key);
    else {
        if (cur->key < key) cur->right = deleteNode_BS(cur->right, key);
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
                } else {
                    parent->right = succ->right;
                }
                cur->key = succ->key;
                delete succ;
            }
        }
        return cur;
    }
}

void insertNode_Level(Node* &cur, int key) {
    if (cur == NULL) {
        cur = createNode(key);
        return;
    }

    queue<Node*> q;
    q.push(cur);

    while (!q.empty()) {
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

void traverseLevelOrder(Node* cur) {
    if (!cur) return;

    queue<Node*> q;
    q.push(cur);

    while(!q.empty()) {
        int qSize = q.size();

        for (int _ = 0; _ < qSize; _++) {
            Node* temp = q.front();
            q.pop();

            if (temp) {
                cout << temp->key << " ";
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}

void traversePreorder(Node* cur) {
    if (!cur) {
        return;
    }   
    cout << cur->key << " ";
    traversePreorder(cur->left);
    traversePreorder(cur->right);
}

void traversePreorderIterative(Node* root) {
    stack<Node*> stack;

    if (root == NULL) return;
    stack.push(root);

    while (!(stack.empty())) {
        Node* curr = stack.top();
        stack.pop();
        cout << curr->key << " ";

        if (curr->right != NULL) stack.push(curr->right);
        if (curr->left != NULL) stack.push(curr->left);
    }
    return;
}

void traverseInorder(Node* cur) {
    if (!cur) {
        return;
    }   
    traverseInorder(cur->left);
    cout << cur->key << " ";
    traverseInorder(cur->right);
}

void traverseInorderInterative(Node* root) {
    stack<Node*> stack;

    while(root || !(stack.empty())) {
        while (root) {
            stack.push(root);
            root = root->left;
        }

        root = stack.top();
        stack.pop();
        cout << root->key << " ";
        root = root->right;
    }
    return;
}

void traversePostorder(Node* cur) {
    if (!cur) {
        return;
    }   
    traversePostorder(cur->left);
    traversePostorder(cur->right);
    cout << cur->key << " ";
}

void findPaths(Node* curr, int sum, string &path) {
    if (!curr) return;

    string currKey = to_string(curr->key);
    path += currKey + " ";

    if (!(curr->left) && !(curr->right) && sum == curr->key) {
        cout << path << endl;
    }

    findPaths(curr->left, sum - curr->key, path);
    findPaths(curr->right, sum - curr->key, path);
    path = path.substr(0, path.size() - currKey.size() - 1);
}

void getAllPaths(Node* root, int sum) {
    string path;
    findPaths(root, sum, path);
    return;
}

int countLeafNode(Node* cur) {
    if (cur == NULL) return 0;
    if (cur->left == NULL && cur->right == NULL) return 1;
    
    return countLeafNode(cur->left) + countLeafNode(cur->right);
}

int getMaxValSmallerThanX(Node* cur, int target) {
    int res = INT_MIN;
    Node* temp = cur;

    while (temp != NULL) {
        if (temp->key < target) {
            res = max(temp->key, res);
        } 

        if (temp->key < target) {     
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
    return res;
}

// int countNodes(Node* root) {
//     if (root == NULL) return 0;

//     return (1 + countNodes(root->left) + countNodes(root->right));
// }

// bool isComplete(Node* root, int index = 0, int number_nodes) {
//     if (root == NULL) return true;

//     if (index >= number_nodes) return false;

//     return isComplete(root->left, 2*index + 1, number_nodes) && isComplete(root->right, 2 * index + 2, number_nodes);

// }

int main() {
    Node* root = createNode(10);
    // insertNode_BS_NoRecursion(root, 5);
    // insertNode_BS_NoRecursion(root, 15);
    // insertNode_BS_NoRecursion(root, 2);
    // insertNode_BS_NoRecursion(root, 8);
    // // insertNode_BS_NoRecursion(root, 13);
    // insertNode_BS_NoRecursion(root, 17);
    //cout << getMaxValSmallerThanX(root, 6);

    // insertNode_BS(root, 5);
    // insertNode_BS(root, 15);
    // insertNode_BS(root, 2);
    // insertNode_BS(root, 8);
    // insertNode_BS(root, 13);
    // insertNode_BS(root, 17);
    // deleteNode_BS(root, 10);
    // cout << searchNode_BS(root, 0);
    // cout << searchNode_BS(root, 2);
    
    cout << countLeafNode(root);
    // traverseInorder(root);
    // traverseInorderInterative(root);
    // cout << endl;
    // getAllPaths(root, 23);
    // traversePreorder(root);
    // traverseInorder(root);
    // traversePostorder(root);
    return 0;
}