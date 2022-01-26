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
    void inorder(TreeNode* root,vector<int> &list)
    {
        if(root==NULL)
            return ;
        inorder(root->left,list);
        list.push_back(root->val);
        inorder(root->right,list);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1,list2,ans;
        inorder(root1,list1);
        inorder(root2,list2);
        int p1=0,p2=0;
       while(p1<list1.size() && p2<list2.size())
       {
           if(list1[p1]<list2[p2])
           {
                ans.push_back(list1[p1++]);
           }
           else
                ans.push_back(list2[p2++]);
       }
           
        while(p1<list1.size())
            ans.push_back(list1[p1++]);
                 
        while(p2<list2.size())
            ans.push_back(list2[p2++]);
           
        return ans;
    }
};