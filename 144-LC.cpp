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

 #include<bits/stdc++.h>
 using namespace std;
 

class Solution
{
public:
    vector<int> ans;

    void f(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        ans.push_back(root->val);
        f(root->left);
        f(root->right);
        return;
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        f(root);
        return ans;
    }
};