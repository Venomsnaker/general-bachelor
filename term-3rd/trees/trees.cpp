#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int val) {
        this->val = val;
        left = right = NULL;
    }
};

class BinaryTree {
    Node *root;

    public:
        Node* CreateNode(int val) {
            Node* newNode = new Node(val);
            if (!newNode) {
                cout << "Memory Error \n";
                return NULL;
            }
            return newNode;
        }

        void InsertNode(int val) {
            if (root == NULL) {
                root = CreateNode(val);
                return;
            }

            queue<Node*> q;
            q.push(root);

            while (!q.empty()) {
                Node* temp = q.front();
                q.pop();

                if(temp->left != NULL) q.push(temp->left);
                else {
                    temp->left = CreateNode(val);
                    return;
                }

                if(temp->right != NULL) q.push(temp->right);
                else {
                    temp->right = CreateNode(val);
                    return;
                }
            }
        }

        void PrintTree() {
            vector<int> nodes;
            InorderTraversal(root, nodes);
            for (int i = 0; i < nodes.size(); i++) cout << nodes[i] << endl;
        }

    private:
        // All basic traversal types
        // Time Complexity: O(n)
        // Space Complexity: O(1)
        void InorderTraversal(Node *root, vector<int> &nodes) {
            if (!root) return;
            InorderTraversal(root->left, nodes);
            nodes.push_back(root->val);
            InorderTraversal(root->right, nodes);
        }

        void PreorderTraversal(Node *root, vector<int> &nodes) {
            if (!root) return;
            PreorderTraversal(root->left, nodes);
            nodes.push_back(root->val);
            PreorderTraversal(root->right, nodes);
        }

        void PostorderTraversal(Node *root, vector<int> &nodes) {
            if (!root) return;
            PostorderTraversal(root->left, nodes);
            nodes.push_back(root->val);
            PostorderTraversal(root->right, nodes);
        }
};

int main() {
    BinaryTree tree;
    tree.InsertNode(1);
    tree.InsertNode(2);
    tree.InsertNode(3);
    tree.PrintTree();
}
