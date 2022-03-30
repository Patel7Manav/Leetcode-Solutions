class Solution {
public:
    int solve(vector<int>nums,vector<int>&dp,int n)
    {
        if(n==0)
            return nums[0];
        if(n<0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int single=solve(nums,dp,n-1);
        int doubl=nums[n]+ solve(nums,dp,n-2);
        return dp[n]=max(single,doubl);
    }
    int rob(vector<int>& nums) {
       int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,dp,n-1);
    }
};