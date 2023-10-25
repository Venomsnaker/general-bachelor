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

        void DeleteNode(int val) {
            if (root == NULL) return;

            if (root->left == NULL && root->right == NULL) {
                if (root->val == val) return;
                else return;
            }

            queue<Node*> q;
            q.push(root);
            Node* temp;
            Node* d_node = NULL;

            while (!q.empty()) {
                temp = q.front();
                q.pop();

                if (temp->val == val) {
                    d_node = temp;
                }

                if(temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            if (d_node != NULL) {
                int x = temp->val;
                DeleteDeepestNode(temp);
                d_node->val = x;
            }
            return;
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

        int MaxDepth(Node* node) {
            if (node == NULL) return 0;
            else {
                int lDepth = MaxDepth(node->left);
                int rDepth = MaxDepth(node->right);
                if (lDepth > rDepth) {
                    return (lDepth + 1);
                }else {
                    return (rDepth + 1);
                }
            }
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

        void DeleteDeepestNode(struct Node* d_node) {
            queue<Node*> q;
            Node* temp;
            q.push(root);

            // Level order traversal until the last node
            while (!q.empty()) {
                if (temp == d_node) {
                    temp = NULL;
                    delete(d_node);
                    return;
                }

                if (temp->right) {
                    if (temp->right == d_node) {
                        temp->right = NULL;
                        delete(d_node);
                        return;
                    } else {
                        q.push(temp->right);
                    }
                }

                if (temp->left) {
                    if (temp->left == d_node) {
                        temp->left = NULL;
                        delete(d_node);
                        return;
                    } else {
                        q.push(temp->left);
                    }
                }
            }
        }
};

int main() {
    BinaryTree tree;
    tree.InsertNode(1);
    tree.InsertNode(2);
    tree.InsertNode(3);
    tree.PrintTree();
}
