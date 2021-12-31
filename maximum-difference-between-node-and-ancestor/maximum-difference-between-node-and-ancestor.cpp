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
    int traverse(TreeNode * root,int mx,int mn)
    {
        if(root==NULL)
            return -1;
        int ans= max(abs(root->val-mx),abs(root->val-mn));
        mx=max(mx,root->val);
        mn=min(mn,root->val);
        return max(ans,max(traverse(root->left,mx,mn),traverse(root->right,mx,mn)));
    }
    int maxAncestorDiff(TreeNode* root) {
        
        return
            max(
            traverse(root->left,root->val,root->val),
            traverse(root->right,root->val,root->val)
         );
    }
};