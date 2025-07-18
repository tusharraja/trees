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



 const int mod=1e9+7;
class Solution {
public:
vector<int> arr;

typedef long long ll;


ll f(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    if(root->left ==nullptr and root->right==nullptr){
        arr.push_back(root->val);
        return root->val;
    }
    ll lv=f(root->left);
    ll rv=f(root->right);

    arr.push_back((root->val+lv+rv)  );

    return arr.back();

}
    int maxProduct(TreeNode* root) {

        f(root);
        long long ans=0;
        int n=arr.size();
        long long sum=arr[n-1];
        for(long long x:arr){
            // cout<<x<<" ";
            ans=max(ans,((sum-x)*x)) ;

        }
        return ans%mod;
        
    }
};