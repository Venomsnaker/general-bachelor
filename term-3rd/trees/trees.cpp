#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class BinaryTree
{
public:
    // Recursive Tree Traversals
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> nodes;
        helper(root, nodes);
        return nodes;
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> nodes;
        helper(root, nodes);
        return nodes;
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> nodes;
        helper(root, nodes);
        return nodes;
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // Time Complexity: O(n)
        // Space Complexity: O(n)
        vector<vector<int>> res;
        queue<TreeNode *> temp;
        temp.push(root);

        while (!temp.empty())
        {
            int curLen = temp.size();
            vector<int> curLevel;

            for (int i = 0; i < curLen; i++)
            {
                TreeNode *node = temp.front();
                temp.pop();
                if (node != NULL)
                {
                    curLevel.push_back(node->data);
                    temp.push(node->left);
                    temp.push(node->right);
                }
            }

            if (curLevel.size())
            {
                res.push_back(curLevel);
            }
        }
        return res;
    }

private:
    void helper(TreeNode *root, vector<int> &nodes)
    {
        if (!root)
            return;

        helper(root->left, nodes);
        nodes.push_back(root->data);
        helper(root->right, nodes);
    }
};

void TraverseInorder(struct TreeNode *root)
{
    stack<TreeNode *> s;
    TreeNode *curr = root;

    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main()
{
    return 0;
}
