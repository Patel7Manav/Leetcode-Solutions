class Solution {
public:
    int solve(int n,int cop,int curr,vector<vector<int>>&dp)
    {
        if(curr>n)
            return 1e8;
        if(curr==n)
            return 0;
        if(dp[cop][curr]!=0)
            return dp[cop][curr];
        int left=1e8;
        if(cop!=0)
         left=1+solve(n,cop,curr+cop,dp);  
        int right=2+solve(n,curr,curr+curr,dp);
        return dp[cop][curr]=min(left,right);
    }
    int minSteps(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        if(n==1)
            return 0;
        if(n==2)
            return 2;
       return solve(n,0,1,dp);
    }
};