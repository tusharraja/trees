#include<bits/stdc++.h>
using namespace std;

int main(){

   return 0;
}

///**
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
 vector<vector<int>> ans;
 void f(TreeNode* root, int s,vector<int> ds){
    if(root==nullptr){
        return;
    }
    if(root->right==nullptr and root->left==nullptr){
        if(s==root->val){
            ds.push_back(root->val);
            ans.push_back(ds);
           
        }
        return;
    }

    ds.push_back(root->val);
    f(root->left,s-root->val,ds);

    f(root->right,s-root->val,ds);

    return;




 }
    vector<vector<int>> pathSum(TreeNode* root, int s) {
        vector<int> ds;
        f(root,s,ds);
        return ans;
        
    }
};