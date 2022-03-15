class Solution {
public:
        void comb(int ind,vector<int>&a,vector<int>&candidates,int target,vector<vector<int>>&ans)
        {
            if(ind==candidates.size())
            {
                return;
            }
            if(target==0)
            {
                ans.push_back(a);
                return;
            }
            if(target>=candidates[ind])
            {
                a.push_back(candidates[ind]);
                target-=candidates[ind];
                comb(ind,a,candidates,target,ans);
                target+=candidates[ind];
                a.pop_back();
            }
            comb(ind+1,a,candidates,target,ans);
        }
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> a;
        comb(0,a,candidates,target,ans);
        return ans;
    }
};