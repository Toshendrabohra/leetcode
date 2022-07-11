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
class Solution {
public:
    void right(TreeNode* root, vector<int> &ans,int cur,int &mx)
    {
        if(root == NULL)
            return ;
        if(cur>mx)
        {
            mx++;
            ans.push_back(root->val);
        }
        right(root->right,ans,cur+1,mx);
        right(root->left,ans,cur+1,mx);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        int mx = -1;
        vector<int> ans;
        right(root, ans,0,mx);
        return ans;
    }
};