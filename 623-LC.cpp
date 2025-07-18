#include<bits/stdc++.h>
using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:

void f(TreeNode* root, int val, int depth,int cur){

    if(root==nullptr){
        return;
    }

    if(depth==cur){
        auto l=root->left;
        auto r=root->right;
        root->left= new TreeNode(val);
        root->right= new TreeNode(val);
        root->left->left=l;
        root->right->right=r;
        return;
    }

    f(root->left,val,depth,cur+1);
    f(root->right,val,depth,cur+1);

    







}



    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        int cur=1;

        if(depth==1){

            auto newnode= new TreeNode(val);
            newnode->left=root;
            return newnode;


        }
        else{

        f(root,val,depth-1,cur);

        }
        
        return root;
    }
};