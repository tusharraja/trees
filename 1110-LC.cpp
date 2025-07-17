
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
  //TC : O(N)
  //SC : O(N)

 #include<bits/stdc++.h>
 using namespace std;
 

class Solution {
public:
vector<TreeNode*> ans;
set<int> s;

TreeNode* f(TreeNode* root){

    if(root==NULL){
        return NULL;
    }

    root->left=f(root->left);
    root->right=f(root->right);

    if(s.find(root->val)==s.end()){
        return root;
    }
    else{
        if(root->left){
            ans.push_back(root->left);
        }
         if(root->right){
            ans.push_back(root->right);
        }
        return nullptr;

    }




}

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        for(auto x:to_delete){
            s.insert(x);
        }
        f(root);
        if(s.find(root->val)==s.end()){
            ans.push_back(root);
        }

        return ans;
        
    }
};