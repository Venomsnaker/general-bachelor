#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int key) {
        left = NULL;
        right = NULL;
        this->key = key;
        this->height = 0;
    }

    Node() {
        key = 0;
        height = 0;
        left = NULL;
        right = NULL;
    }
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

class AVLTree {
public:
    Node* root;

    AVLTree(int key) {
        root = create_node(key);
    }

    int get_node_height(Node* n) {
        if (n == NULL) {
            return 0;
        }
        else return n->height;
    }

    void update_node_height(Node* node) {
        node->height = max(get_node_height(node->left), get_node_height(node->right)) + 1;
    }

    Node* create_node(int key) {
        Node* newNode = new Node(key);
        newNode->height = 1;
        return newNode;
    }

    Node* right_rotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        update_node_height(y);
        update_node_height(x);
        return x;
    }

    Node* left_rotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        update_node_height(x);
        update_node_height(y);
        return y;
    }

    int get_balance(Node* cur) {
        if (cur == NULL) return 0;
        return get_node_height(cur->left) - get_node_height(cur->right);
    }

    Node* insert_node(Node* &cur, int key) {
        if (cur == NULL) {
            return create_node(key);
        }

        if (key < cur->key)
            cur->left = insert_node(cur->left, key);
        else if (key > cur->key)
            cur->right = insert_node(cur->right, key);
        else return cur;

        update_node_height(cur);

        int balance = get_balance(cur);

        if (balance > 1 && key < cur->left->key)
            return right_rotate(cur);

        if (balance < -1 && key > cur->right->key)
            return left_rotate(cur);

        if (balance > 1 && key > cur->left->key)
        {
            cur->left = left_rotate(cur->left);
            return right_rotate(cur);
        }

        if (balance < -1 && key < cur->right->key)
        {
            cur->right = right_rotate(cur->right);
            return left_rotate(cur);
        }
        return cur;
    }

    void print_tree(Node* cur) {
        if (!cur) return;
        cout << "Node: " << cur->key << " - Height: " << cur->height << " " << endl;
        print_tree(cur->left);
        print_tree(cur->right);
    }

    bool checkAVL_recursive(Node* node) {
        if (node == NULL) return true;

        int k = abs(get_node_height(node->left) - get_node_height(node->right));
        if (k > 1) return false;
        return checkAVL_recursive(node->left) && checkAVL_iterative(node->right);
    }

    bool checkAVL_iterative(Node* node) {
        if (node == NULL) return true;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            int qSize = q.size();
            while (qSize > 0) {
                Node* cur = q.front();
                int leftHeight = get_node_height(cur->left);
                int rightHeight = get_node_height(cur->right);

                if (abs(rightHeight - leftHeight) > 1) return false;
                q.pop();

                if (cur->left != NULL) q.push(cur->left);
                if (cur->right != NULL) q.push(cur->right);
                qSize--;
            }
        }
        return true;
    }
};

void demonstrate_AVL_tree() {
    AVLTree tree(5);
    cout << "Traverse in preorder the pre-initialize tre: " << endl;
    tree.root = tree.insert_node(tree.root, 3);
    tree.root = tree.insert_node(tree.root, 2);
    tree.root = tree.insert_node(tree.root, 4);
    tree.root = tree.insert_node(tree.root, 11);
    tree.root = tree.insert_node(tree.root, 9);
    tree.root = tree.insert_node(tree.root, 12);
    tree.root = tree.insert_node(tree.root, 13);
    tree.root = tree.insert_node(tree.root, 14);
    tree.print_tree(tree.root);
    cout << "Is this an AVL Tree: " << tree.checkAVL_iterative(tree.root);
    //cout << "Insert more element: " << endl;
}

int main()
{
    demonstrate_AVL_tree();
    return 0;
}
