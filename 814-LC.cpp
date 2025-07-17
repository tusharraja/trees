// check(root)        → visits n nodes  
// check(root->left)  → visits n–1 nodes  
// check(root->left->left) → visits n–2 nodes  

//So the total work is on the order of
// n + (n-1) +... +1 = o(n ^2)



 //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

 #include<bits/stdc++.h>
 using namespace std;
 

class Solution {
public:

bool check(TreeNode * root){
    if(root==nullptr){
        return false;
    }

    if(root->val==1){
        return true;
    }

    
    bool l= check(root->left);
    bool r=check(root->right);

    return l or r;


}

TreeNode* f(TreeNode * root){

    if(root==nullptr){
        return root;
    }
    
    if(check(root->left)==true){
    root->left=f(root->left);
    }
    else{
        root->left=nullptr;
    }
    
        if(check(root->right)==true){
    root->right=f(root->right);
    }
    else{
        root->right=nullptr;
    }

    return root;


}
    TreeNode* pruneTree(TreeNode* root) {

        

        auto x= f(root);
        if(x->right==nullptr and x->left==nullptr){
            if(x->val==0){
                return nullptr;
            }
        }
        return x;
        
    }
};