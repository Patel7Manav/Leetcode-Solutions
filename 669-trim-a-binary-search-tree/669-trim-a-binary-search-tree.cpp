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
    TreeNode* solve(TreeNode *root,int l,int r)
    {
        if(root==NULL)
            return NULL;
        if(root->val<l)
        {
           
            return solve(root->right,l,r);
            
        }
        else if(root->val>r)
        {   
            return solve(root->left,l,r);
         
        }
        else
        {
            root->left=solve(root->left,l,r);
            root->right=solve(root->right,l,r);
        }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
       return solve(root,low,high);
    }
};