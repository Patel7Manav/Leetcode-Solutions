class Solution {
public:
    int solve(vector<vector<int>>&matrix,int r,int c,int n,vector<vector<int>>&dp)
    {   if(c<0 || c>=n)
        return INT_MAX;
        if(r==n-1) 
            return matrix[r][c];
     if(dp[r][c]!=INT_MAX)
         return dp[r][c];
        int one =solve(matrix,r+1,c+1,n,dp);
        int two =solve(matrix,r+1,c-1,n,dp);
        int three =solve(matrix,r+1,c,n,dp);
        return dp[r][c]=matrix[r][c]+min(min(one,two),three);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        int mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mn=min(mn,solve(matrix,0,i,n,dp));
        }
        return mn;
    }
};