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
    int find_sum(TreeNode* root,int num)
    {
        
        if(root==NULL)
        {
           return 0;
        }
        else if(root->left==NULL && root->right==NULL)
        {
            
            return 2*num+root->val;
        }
        else
            return find_sum(root->left,num*2+root->val)+find_sum(root->right,2*num+root->val);
    }
    int sumRootToLeaf(TreeNode* root) {
        return find_sum(root,0);
    }
};