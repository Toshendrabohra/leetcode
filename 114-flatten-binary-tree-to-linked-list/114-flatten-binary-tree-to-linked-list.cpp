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
    void helper(TreeNode* root, TreeNode* &head)
    {
        if(root == NULL)
            return;
        helper(root->right, head);
        helper(root->left, head);
        
        root->left = NULL;
        root->right = head;
        head = root;
    }
    
    void flatten(TreeNode* root) {
        TreeNode* head = NULL;
        helper(root, head);
    }
};