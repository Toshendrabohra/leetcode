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
    void traverse(TreeNode* root, int row, int col, vector<vector<int>> &ans)
    {
        if(root == NULL)    
            return;
        
        ans.push_back({col, row, root->val});
        
        traverse(root->left, row+1, col-1, ans);
        traverse(root->right, row+1, col+1, ans);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        traverse(root, 0, 0, ans);
        
        sort(ans.begin(), ans.end());
        
        vector<vector<int>> fin;
        
        int cur = INT_MIN;
        vector<int> dum;
        
        for(int i = 0; i < ans.size(); i++)
        {
            if(ans[i][0]> cur)
            {
                cur = ans[i][0];
                if(!dum.empty())
                    fin.push_back(dum);
                dum.clear();
            }
            
            dum.push_back(ans[i][2]); 
        }
        
           if(!dum.empty())
                    fin.push_back(dum);
        
        return fin;
        
    }
};