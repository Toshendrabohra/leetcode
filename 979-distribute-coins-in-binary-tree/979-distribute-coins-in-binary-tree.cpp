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
    void count(int &ans, TreeNode* root, int &kangle, int &malamal)
    {
        if(root == NULL)
            return;
        int lk = 0, lm = 0, rm = 0, rk = 0;
        count(ans, root->left, lk, lm);
        count(ans, root->right, rk, rm);
        
        kangle =  lk + rk;
        malamal = lm + rm;
         ans += kangle + malamal;
        
        if( root -> val == 0)
        {
            
                kangle++;
        }
        else if(root -> val >1)
        {
            malamal += root->val - 1; 
           
        }
      
                int rem = min(malamal, kangle);
                kangle -= rem;
                malamal -= rem;
            
       
    }
    
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        int kangle = 0;
        int malamal = 0;
        count(ans, root, kangle, malamal);
        
        return ans;
    }
};