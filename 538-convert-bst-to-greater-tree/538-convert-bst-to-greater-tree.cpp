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
    vector<int>arr;
    int tum=0;
    int ind=-1;
    void find(TreeNode* root){
         if(root==NULL)
           return ;
        find(root->left);
tum+=root->val;
        arr.push_back(tum);
        find(root->right);
    }
     void sum(TreeNode*root){
        if(root==NULL)
           return ;
        sum(root->left);
        root->val=tum;
        if(ind!=-1)
            root->val-=arr[ind];
        ind++;
        sum(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
       find(root);
        sum(root);
        return root; 
    }
};