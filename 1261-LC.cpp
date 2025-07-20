
 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 //*/
#include<bits/stdc++.h>
using namespace std;


class FindElements
{
public:
    unordered_set<int> s;

    void f(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return;
        }
        s.insert(val);
        if (root->left)
        {
            f(root->left, 2 * val + 1);
        }
        if (root->right)
        {
            f(root->right, 2 * val + 2);
        }
    }
    FindElements(TreeNode *root)
    {
        f(root, 0);
    }

    bool find(int target)
    {
        return s.find(target) != s.end();
    }
};

// TC O(N)
