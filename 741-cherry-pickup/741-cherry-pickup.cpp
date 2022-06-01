class Solution {
public:
   
    int solve(vector<vector<int>>&grid,int i,int j,int k,int l,int n,vector<vector<vector<vector<int>>>>&dp)
    {
        if(i>=n || j>=n || k>=n || l>=n || grid[i][j]==-1 || grid[k][l]==-1)
        {
            return -1e8;
        }
        if(i==n-1 && j==n-1)
            return grid[i][j];
       if(k==n-1 && l==n-1)
           return grid[k][l];
        if(dp[i][j][k][l]!=-1)
            return dp[i][j][k][l];
        int sum=0;
        if(l==j && i==k)
            sum=grid[i][j];
        else
            sum=(grid[i][j]+grid[k][l]);
        return dp[i][j][k][l]=sum+max(max(max(solve(grid,i,j+1,k,l+1,n,dp),solve(grid,i,j+1,k+1,l,n,dp)),solve(grid,i+1,j,k,l+1,n,dp)),solve(grid,i+1,j,k+1,l,n,dp));
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
 vector<vector<vector<vector<int>>>>dp(n+1,vector<vector<vector<int>>>(n+1,vector<vector<int>>(n+1,(vector<int>(n+1,-1)))));       
        int ans= solve(grid,0,0,0,0,n,dp);
        if(ans<0)
            return 0;
        else
            return ans;
    }
};