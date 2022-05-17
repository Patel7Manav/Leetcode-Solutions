class Solution {
public:
   long int solve(int n,int abs,int late,vector<vector<vector<long int>>>&dp)
    {
        if(n==0)
       return 1;
        
        if(dp[n][abs][late]!=-1)
            return dp[n][abs][late];
      long  int pres=solve(n-1,abs,0,dp);
        
        long int ab=0,la=0; 
            if(abs<1)
            ab=solve(n-1,abs+1,0,dp); 
            if(late<2)
            la=solve(n-1,abs,late+1,dp);
        return dp[n][abs][late]=(pres%1000000007+ab%1000000007+la%1000000007)%1000000007;
    }
    int checkRecord(int n) {
        int abs=0,late=0;
        vector<vector<vector<long int>>>dp(n+1,vector<vector<long int>>(2,vector<long int>(3,-1)));
        return solve(n,abs,late,dp); 
    }
};