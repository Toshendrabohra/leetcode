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
       //occ == monitored
    
    void count(TreeNode* root, int &cam_here, int &no_cam_here, int &occ, int &nocc) 
    {
        int lc,nlc,locc,lnocc,rc,nrc,rocc,rnocc;
       
        if( root -> left ==NULL && root -> right ==NULL)
        {
            cam_here = 1;
            no_cam_here = 0;
            nocc = 0;
            occ = 1;
            return;
        }
        else if(root -> left == NULL)
        {
            count(root->right, rc, nrc, rocc, rnocc);
            cam_here = 1 + min(rocc, rnocc);
            no_cam_here = rc;
            occ = min (cam_here, no_cam_here);
            nocc = min (occ, rocc);
            return;
        }
        else if(root -> right == NULL)
        {
            count(root->left, lc, nlc, locc, lnocc);
            cam_here = 1 + min(locc, lnocc);
            no_cam_here = lc;
            occ = min (cam_here, no_cam_here);
            nocc = min (occ, locc);
            
            return;
        }
        
        count(root->left, lc, nlc, locc, lnocc);
        count(root->right, rc, nrc, rocc, rnocc);
        
        cam_here = min(locc, lnocc)+min(rocc, rnocc) + 1;
        no_cam_here = min(locc + rc, rocc + lc) ;
        occ = min(cam_here, no_cam_here);
        nocc = locc + rocc ;
      // cout<<root->val << cam_here <<" "<<no_cam_here<<" "<<occ<<" "<<nocc<<endl;
    }
    int minCameraCover(TreeNode* root) {
        int cam_here, no_cam_here, occ, nocc;
       count(root, cam_here, no_cam_here, occ, nocc);
       return occ;
    }
};