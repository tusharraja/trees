#include<bits/stdc++.h>
using namespace std;

//LINK TO PROBLEM
// https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1


struct Node
{
    int data;
    Node* left;
    Node* right;
}; 

// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int f(Node* root){
        if(root==NULL){
            return 0;
        }
        if(root->left ==nullptr and root->right==nullptr){
            return 1;
        }
        int lcount=f(root->left);
        int rcount=f(root->right);
        return lcount+rcount;
    }
    int countLeaves(Node* root) {
        // write code here
        return f(root);
        
        
    }
};