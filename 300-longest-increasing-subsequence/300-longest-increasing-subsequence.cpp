class Solution {
public:
    int solve(vector<int>&nums,int ind,int curr,vector<vector<int>>&dp)
    {
        if(ind==nums.size())
            return 0;
        if(dp[ind][10001+curr]!=-1)
            return dp[ind][10001+curr];
        int pick=0;
        if(nums[ind]>curr)
        {
             pick=1+solve(nums,ind+1,nums[ind],dp);
        }
        int nopick=solve(nums,ind+1,curr,dp);
        return dp[ind][10001+curr]= max(pick,nopick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<vector<int>>dp(n,vector<int>(20002,-1));
        for(int i=0;i<n;i++)
        {
           ans=max(1+solve(nums,i+1,nums[i],dp),ans);
        }
        return ans;
    }
};