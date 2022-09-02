class Solution {
public:
    bool dfs(int i,int j, int m, int n, vector<vector<int>>&grid2,vector<vector<int>>&grid1)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid2[i][j]==0)
        {
            return true;
        }
        if(grid2[i][j]!=grid1[i][j])
            return false;
        grid2[i][j]=0;
        bool a=dfs(i-1,j,m,n,grid2,grid1);
        bool b=dfs(i+1,j,m,n,grid2,grid1);
        bool c=dfs(i,j-1,m,n,grid2,grid1);
        bool d=dfs(i,j+1,m,n,grid2,grid1);
        return a&&b&&c&&d; 
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size(),n=grid1[0].size(),ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid2[i][j]==1)
                {
                    if(dfs(i,j,m,n,grid2,grid1))
                        ans++;
                }
            }
        }
        return ans;
    }
};