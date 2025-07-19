/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int ans = 0;
    string f(TreeNode *root, string s)
    {

        if (root == nullptr)
        {
            return "0";
        }

        if (root->left == nullptr and root->right == nullptr)
        {
            // cout<<ans<<"after is ";
            ans = ans + stoi(s + to_string(root->val));
            // cout<<ans;
            // cout<<endl;
            return ",";
        }

        string a = to_string(root->val);
        string l = f(root->left, s + a);
        string r = f(root->right, s + a);

        return ",.,l,";
    }
    int sumNumbers(TreeNode *root)
    {
        string s;
        f(root, s);
        return ans;
    }
};