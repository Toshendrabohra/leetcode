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
     bool bst(TreeNode*  root,long int mx,long int mn)
    {
        if(root==NULL)return true;
        if(root->val>=mx || root->val<=mn)
        return false;
        return (bst(root->left,min(mx,(long)root->val),mn) && bst(root->right,mx,max((long)root->val,mn)));
    }
    bool isValidBST(TreeNode* root) {
          return   bst(root,(long)INT_MAX+1,(long)INT_MIN-1);
    }
};