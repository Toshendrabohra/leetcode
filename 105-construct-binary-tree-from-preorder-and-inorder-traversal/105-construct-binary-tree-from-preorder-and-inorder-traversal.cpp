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
        TreeNode * new_node(int va)
  {
       TreeNode * nw=new TreeNode ;
      nw->val=va;
      nw->left=NULL;
      nw->right=NULL;
      return (nw);
  }
       int indx;
     int search(vector<int>& in,int start,int end ,int va)
  {
      for(int i=start;i<=end;i++)
      {
          if(in[i]==va)
          return i;
      }
      return -1;
  }
      TreeNode* build( vector<int>& in,vector<int>& pre,int start,int end)
    {
        if(start>end)
        return NULL;
        
         TreeNode *newnode= new_node(pre[indx++]);
        if(start==end)
        return newnode;
        int pos=search(in,start,end,newnode->val);
        newnode->left=build(in,pre,start,pos-1);
        newnode->right=build(in,pre,pos+1,end);
        return newnode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        indx=0;
        return build(inorder,preorder,0,inorder.size()-1);
    }
};