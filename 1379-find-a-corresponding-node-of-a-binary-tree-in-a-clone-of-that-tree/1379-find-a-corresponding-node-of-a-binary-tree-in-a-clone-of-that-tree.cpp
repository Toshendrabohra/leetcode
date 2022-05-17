/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* dfs(TreeNode * root , TreeNode* target)
    {
        if(root==NULL)
            return NULL;
        if(target->val==root->val)
            return root;
        TreeNode * l=dfs(root->left, target);
        if(l)        
        return l;
        
        TreeNode * r=dfs(root->right, target);
        
        return r;
        

            
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(cloned,target);
    }
};