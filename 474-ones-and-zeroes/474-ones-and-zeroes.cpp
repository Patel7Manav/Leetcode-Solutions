class Solution {
public:
    int solve(vector<string>&strs,int m,int n,int ind,vector<vector<vector<int>>>&dp)
    {
        if((m==0 && n==0) || strs.size()<=ind)
            return 0;
        if(dp[m][n][ind]!=-1)
            return dp[m][n][ind];
        int one=0,zero=0,pick=0;
        for(int i=0;i<strs[ind].length();i++)
        {
            if(strs[ind][i]=='1')
                one++;
            else
                zero++;
        }
        if(one<=n && zero<=m)
            pick=1+solve(strs,m-zero,n-one,ind+1,dp);
        int nopick=solve(strs,m,n,ind+1,dp);
        return dp[m][n][ind]=max(pick,nopick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int si=strs.size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(si+1,-1)));
        return solve(strs,m,n,0,dp);
    }
};