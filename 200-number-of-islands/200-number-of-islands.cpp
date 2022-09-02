class Solution {
public:
    void dfs(int i,int j,int m, int n,vector<vector<char>>& grid,vector<vector<bool>>&vis)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0' || vis[i][j]==true )
            return;
        vis[i][j]=true;
        dfs(i-1,j,m,n,grid,vis);
        dfs(i+1,j,m,n,grid,vis);
        dfs(i,j-1,m,n,grid,vis);
        dfs(i,j+1,m,n,grid,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
       int m=grid.size(),n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int c=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    c++;
                    dfs(i,j,m,n,grid,vis);
                }
            }
        }
        return c;
        
    }
};