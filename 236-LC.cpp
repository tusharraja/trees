
#include <bits/stdc++.h>
using namespace std;

// Time Complexity
// You're using a recursive traversal (f) that visits each node once.

//At each node,
//you do constant - time operations : comparisons and recursive calls.

//Time Complexity = O(n),
//where n = total number of nodes in the binary tree.

//Space Complexity
//Recursive call stack is the only additional space used.

//In the worst case (skewed tree),
//the recursion depth can be up to n.

//In the average case (balanced tree),
//the recursion depth is O(log n).




 struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
                                               
};

int main(){

   return 0;
}

         class Solution{
             public:
TreeNode *f(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == p)
    {
        return p;
    }
    if (root == q)
    {
        return q;
    }
    if (root == nullptr)
    {
        return nullptr;
    }
    auto l = f(root->left, p, q);
    auto r = f(root->right, p, q);
    if (l == p and r == q)
    {
        return root;
    }

    if (l == q and r == p)
    {
        return root;
    }

    if (l == nullptr and r != nullptr)
    {
        return r;
    }
    if (r == nullptr and l != nullptr)
    {
        return l;
    }
    return nullptr;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    return f(root, p, q);
}
}
;