#include <bits/stdc++.h>
using namespace std;

// TC O(N)

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;

    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int ans = INT_MIN;

    int f(TreeNode *root)
    {

        if (root == nullptr)
        {
            return INT_MIN / 100;
        }

        if (root->right == nullptr and root->left == nullptr)
        {
            return root->val;
        }

        int leftake = f(root->left);
        int righttake = f(root->right);

        int a = root->val + max(leftake, righttake);

        int f = root->val;

        ans = max({ans, root->val + leftake + righttake, leftake, righttake});

        return max({a, f});
    }
    int maxPathSum(TreeNode *root)
    {

        return max(ans, f(root));
    }
};