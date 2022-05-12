class Solution {
public:
    int solve(vector<int>&perfsq,int n,vector<int>&dp)
    {
         if(n==0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int ans=1e8;
        for(int i=sqrt(n);i>=1;i--)
        {
            ans=min(ans,1+solve(perfsq,n-perfsq[i],dp));
        }
        return dp[n]=ans;
        
    }
    int numSquares(int n) {
        vector<int>perfsq(101,0);
        vector<int>dp(n+1,-1);
        for(int i=1;i<=100;i++)
        {
            perfsq[i]=i*i;
        }
       return solve(perfsq,n,dp);
      
    }
};