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
    bool f(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr and q == nullptr)
        {
            return true;
        }
        if (p != nullptr and q == nullptr)
        {
            return false;
        }
        if (p == nullptr and q != nullptr)
        {
            return false;
        }
        if (p->val != q->val)
        {
            return false;
        }

        bool a = f(p->left, q->left);
        bool b = f(p->right, q->right);
        return a and b;
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return f(p, q);
    }
};