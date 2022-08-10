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
    TreeNode* constructTree(vector<int> &nums, int l, int r)
    {
        if(l==r)
            return new TreeNode(nums[l]);
        else if(r<l)
            return NULL;
        int mid = (l+r)/2;
        TreeNode* dum = new TreeNode(nums[mid]);
        dum->left = constructTree(nums, l,mid-1);
        dum->right = constructTree(nums, mid+1, r);
        
        return dum;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructTree(nums, 0, nums.size()-1);
    }
};