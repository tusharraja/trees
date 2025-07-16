
#include<bits/stdc++.h>
using namespace std;


//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

//  You do a level order traversal (BFS), visiting each node once.

// Time Complexity = O(n)
// where n is the number of nodes in the tree.

//  Space Complexity:
// You use a queue for level order traversal. At most, the queue holds one level of nodes.

// Space Complexity = O(n) (in worst case, bottom level has ~n/2 nodes)


class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *temp = root;

        int fl = 0;

        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                auto f = q.front();
                q.pop();

                if (f->left == nullptr and f->right)
                {
                    return false;
                }

                if (fl == 1)
                {
                    if (f->left or f->right)
                    {
                        return false;
                    }
                }

                if (f->left and f->right == nullptr)
                {
                    fl = 1;
                }
                if (f->left == nullptr and f->right == nullptr)
                {
                    fl = 1;
                }

                if (f->left)
                    q.push(f->left);
                if (f->right)
                    q.push(f->right);
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}