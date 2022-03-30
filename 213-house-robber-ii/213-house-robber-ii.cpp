class Solution {
public:
    int solve(vector<int>&dp,vector<int>nums,int n,bool flag)
    {
        if(flag==true)
        {if(n<1)
            return 0;
        if(n==1)
        {
                return nums[1];
        }
        }
        else
        {
            if(n==nums.size()-1 || n<0)
                return 0;
            if(n==0)
                return nums[0];
        }
        if(dp[n]!=-1)
            return dp[n];
        
        int pick=nums[n]+solve(dp,nums,n-2,flag);
        int nopick=solve(dp,nums,n-1,flag);
        return dp[n]=max(pick,nopick);
        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int>dp(n,-1);
        vector<int>dp2(n,-1);
       return max(solve(dp,nums,n-1,true),solve(dp2,nums,n-2,false));
    }
};