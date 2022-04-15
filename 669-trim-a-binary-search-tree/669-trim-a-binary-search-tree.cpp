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
    bool in_range(int val,int low,int high)
    {
        if(val>=low && val<=high)
            return true;
        return false;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* temp=NULL;
        if(root==NULL)
            return NULL;
        if(in_range(root->val,low,high))
        {
            temp=root;
            temp->left=trimBST(root->left,low,high);
            temp->right=trimBST(root->right,low,high);
        }
        else
        {
            TreeNode* dum;
            dum=trimBST(root->left,low,high);
            if(dum!=NULL)
                return dum;
            else
                return trimBST(root->right,low,high);
        }
            return temp;
    }
};