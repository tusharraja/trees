#include<bits/stdc++.h>
using namespace std;

int main(){

   return 0;
}

//Time Complexity: O(n)

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

int ans=INT_MIN;
pair<int,int> f(TreeNode* root){
    //MIN AND MAX

    if(root==nullptr){
        return {INT_MAX,INT_MIN};
    }

    if(root->left==NULL and root->right==NULL){
        return {root->val,root->val};
    }

    auto lv=f(root->left);
    auto rv=f(root->right);

    int mn=min({lv.first,rv.first,root->val});
    int mx=max({lv.second,rv.second,root->val});

    ans=max({ans,(abs(root->val-mn) ),abs(root->val-mx)} );

    


    return {mn,mx};

}
    int maxAncestorDiff(TreeNode* root) {

        auto fa= f(root);
        return ans;
        
    }
};