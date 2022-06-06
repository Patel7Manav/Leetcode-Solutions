class Solution {
public:
    int dp[101][101][2000];
    int solve(vector<int>&group,vector<int>&profit,int n,int mp,int i,int curr)
    {   
        if(i>=group.size())
        {   if(curr>=mp)
        return 1;
         else
            return 0;
        }
        if(dp[n][i][curr]!=-1)
            return dp[n][i][curr];
        int pick=0;
        if(group[i]<=n)
           pick=solve(group,profit,n-group[i],mp,i+1,curr+profit[i]);
        int nopick=solve(group,profit,n,mp,i+1,curr);
        return dp[n][i][curr]=(pick%1000000007+nopick%1000000007)%1000000007;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int si=group.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(si+1,vector<int>(10001,-1)));
       memset(dp,-1,sizeof(dp)); 
     return solve(group,profit,n,minProfit,0,0);   
    }
};