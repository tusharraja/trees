// https://algo.monster/liteproblems/366
//IT IS A PREMIUM QUESTION ON LEETCODE


//prototype OF FUNCTION TO BE WRITTEN

// vector<vector<int>> findLeaves(TreeNode* root) {
       
//     }


#include<bits/stdc++.h>
using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
  right(right){}
  };
 


  map<int,vector<TreeNode*>> mp;
  vector<vector<int>> ans;

  int f(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    int lh=f(root->left);
    int rh=f(root->right);
    int curh=1+max(lh,rh);
    mp[curh].push_back(root);
    return 1+max(lh,rh);
  }


vector<vector<int>> findLeaves(TreeNode* root) {

    
   
    f(root);
    
 
    for(auto x:mp){
        int heigh=x.first; 
        auto y=x.second;
        cout<<"height of leaf node will be "<<heigh<<"==== ";
        for(auto k:y){
            cout<<k->val<<" ";
        }
        cout<<endl;
    }
    
    return ans;
}

int main(){
    // Let's create a sample binary tree to test the function.
    // Tree structure:
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    //TEST CASE 1
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);


    // Test Case 4: A Fuller, More Complex Tree
// Tree Structure:
//        10
//       /  \
//      5    20
//     / \   / \
//    3   8 15  25
//   /       \
//  1         18
TreeNode* root = new TreeNode(10);
root->left = new TreeNode(5);
root->left->left = new TreeNode(3);
root->left->left->left = new TreeNode(1);
root->left->right = new TreeNode(8);
root->right = new TreeNode(20);
root->right->left = new TreeNode(15);
root->right->left->right = new TreeNode(18);
root->right->right = new TreeNode(25);



    cout << "Running findLeaves function..." << endl;
    cout << "Output from within findLeaves:" << endl;

    
    vector<vector<int>> result = findLeaves(root);

    cout << "\nFunction finished." << endl;
    cout << "The returned vector has " << result.size() << " elements." << endl;


    // It's good practice to free the allocated memory.
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

   return 0;
}
