#include<bits/stdc++.h>
using namespace std;


 //Definition for a binary tree node. 
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


void f(TreeNode* root1,vector<int> &arr){
    if(root1==nullptr){
        return;
    }
    if(root1->left==nullptr and root1->right==nullptr){
        arr.push_back(root1->val);
        return;
    }
    f(root1->left,arr);
    f(root1->right,arr);
}

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr;
vector<int> brr;
        f(root1,arr);
        f(root2,brr);

        // for(auto x:arr){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        //  for(auto x:brr){
        //     cout<<x<<" ";
        // }
        return arr==brr;
        

    }
};

