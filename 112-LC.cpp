#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int s)
    {

        if (root == nullptr)
        {
            return false;
        }

        if (root->left == nullptr and root->right == nullptr)
        {
            if (s == root->val)
            {
                return true;
            }
            return false;
        }

        bool l = false;
        bool r = false;

        l = hasPathSum(root->left, s - root->val);

        r = hasPathSum(root->right, s - root->val);

        return l or r;
    }
};

// ### Time Complexity: O(N)
// N is the total number of nodes in the tree.
// 1.To find a path from the root to a leaf, your function must travel down the tree. In the worst-case scenario, it has to visit every single node to check all possible paths.
// 2. At each node, your code performs a few simple operations: a null check, a subtraction, and a comparison. This is a constant amount of work for each node.
