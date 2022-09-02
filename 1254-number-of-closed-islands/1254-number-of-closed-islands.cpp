class Solution {
public:
    bool dfs(int i,int j,int m, int n,vector<vector<int>>& grid)
    {
        if((i<1 || i>=m-1 || j<1 || j>=n-1) && grid[i][j]==0)
            return true;
         if(grid[i][j]==1)
            return false;
        grid[i][j]=1;
       bool a= dfs(i-1,j,m,n,grid);
        bool b=dfs(i+1,j,m,n,grid);
       bool c= dfs(i,j-1,m,n,grid);
       bool d= dfs(i,j+1,m,n,grid);
        return a||b||c||d;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(grid[i][j]==0)
                {
                    
                    if(!dfs(i,j,m,n,grid))
                        ans++;
                }
            }
        }
        return ans;  
    }
};