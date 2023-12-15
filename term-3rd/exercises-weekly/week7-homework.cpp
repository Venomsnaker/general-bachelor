#include <iostream>
using namespace std;

class TreeNode {
    int *keys;
    int max_children;
    TreeNode **children;
    int n;
    bool leaf;

    public:
        TreeNode(int max_children_int, bool leaf_bool) {
            max_children = max_children_int;
            leaf = leaf_bool;

            keys = new int[2 * max_children - 1];
            children = new TreeNode *[2 * max_children];
            n = 0;
        }

        void traverse() {
            int i = 0;

            for (i = 0; i < n; i++) {
                if (leaf == false) children[i]->traverse();
                cout << " " << keys[i];
            }

            if (leaf == false) {
                children[i] -> traverse();
            }
        }

        TreeNode* search(int k) {
            int i = 0;

            while (i < n && k > keys[i]) i++;
            
            if (keys[i] == k) return this;

            if (leaf == true) return NULL;
            
            return children[i]->search(k);
        }

        void insertNonFull(int k) {
            int i = n - 1;

            if (leaf == true) {
                while (i >= 0 && keys[i] > k) {
                    keys[i + 1] = keys[i];
                    i--;
                }

                keys[i + 1] = k;
                n = n + 1;
            }
        }
};

int main() {
    return 0;
}