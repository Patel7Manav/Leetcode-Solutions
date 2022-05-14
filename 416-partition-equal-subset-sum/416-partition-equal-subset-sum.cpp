class Solution {
public:
    
   bool solve(vector<int>&nums,int ind,int curr,int sum,vector<vector<int>>&dp)
    {
       if(ind==nums.size())
       {
           if((2*curr)==sum)
               return true;
           else
               return false;
       }
        if(dp[ind][curr]!=-1)
            return dp[ind][curr];
        bool take=solve(nums,ind+1,curr+nums[ind],sum,dp);
        bool notake=solve(nums,ind+1,curr,sum,dp);
        return dp[ind][curr]=take || notake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        vector<vector<int>>dp(nums.size(),vector<int>(sum,-1));
        return solve(nums,0,0,sum,dp);
    }
};