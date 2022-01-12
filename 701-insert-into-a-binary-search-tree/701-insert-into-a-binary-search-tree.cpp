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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * dum=new TreeNode(val);
        if(root==NULL)
            return dum;
        else if(root->val>val)
        {
            if(root->left==NULL)
            {
                root->left=dum;
            }
            else
            {
                TreeNode *temp=insertIntoBST(root->left,val);
            }
            
        }
        else
        {
             if(root->right==NULL)
            {
                root->right=dum;
            }
            else
            {
                TreeNode *temp=insertIntoBST(root->right,val);
            }
        }
        return root;
        
    }
};