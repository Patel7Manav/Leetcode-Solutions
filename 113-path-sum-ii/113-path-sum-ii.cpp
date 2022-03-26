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
    void solve(vector<vector<int>>&ans,vector<int>a,TreeNode *root,int sum)
    {   
       if(root==NULL)
           return;
        if(root->left==NULL && root->right==NULL)
        {
            if(sum-root->val ==0)
            {
                a.push_back(root->val);
                ans.push_back(a);
                a.pop_back();
            }
            return;
        }
        a.push_back(root->val);
        solve(ans,a,root->left,sum-root->val);
        solve(ans,a,root->right,sum-root->val);
        a.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>a;
        solve(ans,a,root,targetSum);
        return ans;
    }
};