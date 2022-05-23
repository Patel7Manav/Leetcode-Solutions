class Solution {
public:
    int solve(vector<int>&nums,int ind,int sum,vector<vector<int>>&dp)
    {
        if(ind==nums.size())
        {
            if(sum==0)
                return 0;
            else
                return INT_MIN;
        }
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        int pick=nums[ind]+solve(nums,ind+1,(sum+nums[ind]%3)%3,dp);
        int nopick=solve(nums,ind+1,sum,dp);
        return dp[ind][sum]=max(pick,nopick);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size(),sum=0;
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return solve(nums,0,0,dp);
    }
};