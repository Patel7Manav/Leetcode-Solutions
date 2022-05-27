class Solution {
public:
    int solve(vector<vector<int>>&og,int i,int j,int m,int n, vector<vector<int>>&dp)
    {
       if(i==m-1 && j==n-1 && og[i][j]==0)
           return 1;
        if(i>=m || j>=n || og[i][j]==1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int right=solve(og,i,j+1,m,n,dp);
        int down=solve(og,i+1,j,m,n,dp);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(obstacleGrid,0,0,obstacleGrid.size(),obstacleGrid[0].size(),dp);
    }
};