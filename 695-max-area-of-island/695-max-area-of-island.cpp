class Solution {
public:
    int dfs(int i,int j,int m, int n,vector<vector<int>>& grid)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0 || grid[i][j]==2 )
            return 0;
        grid[i][j]=2;
       return 1+dfs(i-1,j,m,n,grid)+
        dfs(i+1,j,m,n,grid)+
        dfs(i,j-1,m,n,grid)+
        dfs(i,j+1,m,n,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    ans=max(ans,dfs(i,j,m,n,grid));
                }
            }
        }
        return ans;  
    }
};