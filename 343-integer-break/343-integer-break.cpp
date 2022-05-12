class Solution {
public:
    int solve(int n,int c,vector<vector<int>>&dp)
    {   if(n==0)
    {
        if(c<2)
            return -1e7;
        else
            return 1;
    }
     if(dp[n][c]!=-1)
         return dp[n][c];
        int ans=-1e8;
        for(int i=n;i>=1;i--)
        {
            ans=max(ans,i*solve(n-i,c+1,dp));
            
        }
        return dp[n][c]=ans;
    }
    int integerBreak(int n) {
        vector<vector<int>>dp(n+1,vector<int>(58,-1));
        return solve(n,0,dp);
    }
};