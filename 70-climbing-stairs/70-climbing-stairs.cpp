class Solution {
public:
    int solve(vector<int>&dp,int n)
    {   
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int one=solve(dp,n-1);
        int two=solve(dp,n-2);
        return dp[n]=one+two;
    }
    int climbStairs(int n) {
       vector<int>dp(n+1,-1);
       return solve(dp,n);
    }
};