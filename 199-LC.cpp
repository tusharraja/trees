#include<bits/stdc++.h>
using namespace std;
// LC 199
// https://leetcode.com/problems/binary-tree-right-side-view/description/

//author: Tushar Raja

// The space complexity of this algorithm is O(w), where 'w' is the maximum width (or the maximum number of nodes at any single level) of the binary tree.
// The time complexity of this algorithm is O(n), where 'n' is the total number of nodes in the binary tree.

// The algorithm does a level order traversal(BFS) of the binary tree using a queue.
// Every node is visited exactly once, and for each node:
// It is pushed into the queue once.
// It is popped from the queue once.
// Constant-time operations are performed (like checking left, right, and updating temp).


// Definition for a binary tree node on leetcode
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
//GLOBAL ARRAY
    vector<int> ans;
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            int temp;
            while (size--)
            {

                auto f = q.front();
                q.pop();
                if (f->left)
                {
                    q.push(f->left);
                }
                if (f->right)
                {
                    q.push(f->right);
                }
                temp = f->val;
            }

            ans.push_back(temp);
        }

        return ans;
    }
};