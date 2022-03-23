class Solution {
public:
    void solve(vector<vector<int>>&grid,int &ans,int curr,int row,int col)
    {
        
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]==0)
            return;
        curr+=grid[row][col];
        int rest=grid[row][col];
        grid[row][col]=0;
        solve(grid,ans,curr,row-1,col);
        solve(grid,ans,curr,row+1,col);
        solve(grid,ans,curr,row,col-1);
        solve(grid,ans,curr,row,col+1);
        ans=max(ans,curr);
        grid[row][col]=rest;
        curr-=rest;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
       int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
             if(grid[i][j]!=0)   
                solve(grid,ans,0,i,j);
            }
        }
        return ans;
    }
};