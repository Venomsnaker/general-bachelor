#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void TraverseInorder(struct TreeNode* root) {
    stack <TreeNode*> s;
    TreeNode* curr = root;

    while (curr != NULL || s.empty() == false) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main() {
    return 0;
}
