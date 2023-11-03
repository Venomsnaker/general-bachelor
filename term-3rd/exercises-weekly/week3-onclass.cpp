#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int key;
    Node* left, * right;

    Node(int val) {
        this->key = val;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    Node* createNode(int key) {
        Node* new_node = new Node(key);
        return new_node;
    }

    void insertNode(Node*& node, int val) {
        if (node == NULL) {
            node = createNode(val);
            return;
        }

        if (node->key > val) {
            insertNode(node->left, val);
        }
        else {
            // node->key <= val
            insertNode(node->right, val);
        }
    }

    void deleteNode(Node* &node, int val) {
        if (node == NULL) {
            cout << "The value for deletion is not in the tree" << endl;
        }
    }

    int getTreeHeight(Node* cur) {
        if (cur == NULL) return 0;
        return max(1 + getTreeHeight(cur->left), 1 + getTreeHeight(cur->right));
    }

    int getTreeSumLargerThanX(int x) {
        int sum = 0;
        modifyTraverseForSum(root, sum, x);
        return sum;
    }

    bool searchRecursively(Node* node, int val) {
        if (node == NULL) return 0;
        if (node->key == val) return 1;

        if (node->key > val) {
            return searchRecursively(node->left, val);
        }
        else {
            // node->key < val
            return searchRecursively(node->right, val);
        }
    }

    bool searchIteratively(Node* node, int val) {
        int n_temp;
        queue<Node*> temp;
        temp.push(root);

        while (temp.size() != 0) {
            n_temp = temp.size();

            for (int i = 0; i < n_temp; i++) {
                Node* cur = temp.front();
                temp.pop();

                if (cur) {
                    if (cur->key == val) {
                        return 1;
                    }
                    if (cur->left) temp.push(cur->left);
                    if (cur->right) temp.push(cur->right);
                }
            }
            cout << endl;
        }
        return 0;
    }

    void traversePreorder(Node* node) {
        if (!node) return;
        cout << node->key << " ";
        traversePreorder(node->left);
        traversePreorder(node->right);
    }

    void traverseInorder(Node* node) {
        if (!node) return;
        traverseInorder(node->left);
        cout << node->key << " ";
        traverseInorder(node->right);
    }

    void traversePostorder(Node* node) {
        if (!node) return;
        traversePostorder(node->left);
        traversePostorder(node->right);
        cout << node->key << " ";
    }

    void traverseByLevel() {
        int n_temp;
        queue<Node*> temp;
        temp.push(root);

        while (temp.size() != 0) {
            n_temp = temp.size();

            for (int i = 0; i < n_temp; i++) {
                Node* cur = temp.front();
                temp.pop();

                if (cur) {
                    cout << cur->key << " ";
                    if (cur->left) temp.push(cur->left);
                    if (cur->right) temp.push(cur->right);
                }
            }
            cout << endl;
        }
    }

private:
    void modifyTraverseForSum(Node* node, int &sum, int x) {
        if (!node) return;
        modifyTraverseForSum(node->left, sum, x);
        if (root->key > x) { sum += root->key; }
        modifyTraverseForSum(node->right, sum, x);
    }
};

void displayAssigment() {
    // Initialize
    BST tree;
    tree.root = tree.createNode(5);
    tree.insertNode(tree.root, 9);
    tree.insertNode(tree.root, 3);
    tree.insertNode(tree.root, 2);
    tree.insertNode(tree.root, 6);
    tree.insertNode(tree.root, 4);
    tree.insertNode(tree.root, 11);

    // Functions
    cout << "Create a BST with level order traversal (l->r):" << endl;
    tree.traverseByLevel();

    cout << "Preorder Traversal:" << endl;
    tree.traversePreorder(tree.root);
    cout << endl;

    cout << "Inorder Traversal:" << endl;
    tree.traverseInorder(tree.root);
    cout << endl;

    cout << "Postorder Traversal:" << endl;
    tree.traversePostorder(tree.root);
    cout << endl;

    cout << "Tree heigh: " << tree.getTreeHeight(tree.root) << endl;
    cout << "Sum of nodes > 3 = " << tree.getTreeSumLargerThanX(3) << endl;
    cout << "Ton tai nut 4 trong cay (tuan tu): " << tree.searchIteratively(tree.root, 4) << endl;
    cout << "Ton tai nut 1 trong cay (de qui): " << tree.searchRecursively(tree.root, 1) << endl;
}

int main()
{
    displayAssigment();
    return 0;
}
