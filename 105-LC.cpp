#include<bits/stdc++.h>
using namespace std;


//  Definition for a binary tree node.

// With std::map :

//     Building the map : O(n log n)

//                            n lookups during recursion : O(n log n)
//Total : O(n log n)

//                                                             With unordered_map :

//     Building the map : O(n)

//        n lookups during recursion : O(n)
// Total : O(n)

// Overall auxiliary space is :

//     O(n) 
    
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
    map<int, int> mp;
    int idx = 0;
    TreeNode *f(vector<int> &pre, vector<int> &in, int &n, int a, int b)
    {

        if (a < 0 or b >= n)
        {
            return NULL;
        }
        if (a > b)
        {
            return NULL;
        }
        TreeNode *newnode = new TreeNode(pre[idx]);
        int value = pre[idx];
        int x = mp[value];
        idx++;

        newnode->left = f(pre, in, n, a, x - 1);
        newnode->right = f(pre, in, n, x + 1, b);
        return newnode;
    }
    TreeNode *buildTree(vector<int> &pre, vector<int> &in)
    {
        int k = 0;
        int n = pre.size();
        for (int i = 0; i < n; i++)
        {
            mp[in[i]] = i;
        }
        int a = 0;
        int b = n - 1;
        return f(pre, in, n, a, b);
    }
};

int main(){

   return 0;
}