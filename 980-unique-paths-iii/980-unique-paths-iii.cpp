class Solution {
public:
    bool didtravel(vector<vector<int>>&flag)
    {
        for(int i=0;i<flag.size();i++)
        {
            for(int j=0;j<flag[0].size();j++)
            {
                if(flag[i][j]==0)
                    return false;
            }
        }
    return true;
    }
   void solve(vector<vector<int>>&grid,int row,int col,int &ans,vector<vector<int>>&flag)
    {  if(grid[row][col]==2)
    {   
        if(didtravel(flag))
        ans++;
        return;
    }
    if(row-1>=0 && flag[row-1][col]==0)
    {
        flag[row-1][col]=1;
        solve(grid,row-1,col,ans,flag);
        flag[row-1][col]=0;
    }
     if(row+1<grid.size() && flag[row+1][col]==0)
    {
        flag[row+1][col]=1;
        solve(grid,row+1,col,ans,flag);
        flag[row+1][col]=0;
    }
     if(col-1>=0 && flag[row][col-1]==0)
    {
        flag[row][col-1]=1;
        solve(grid,row,col-1,ans,flag);
        flag[row][col-1]=0;
    } 
     if(col+1<grid[0].size() && flag[row][col+1]==0)
    {
        flag[row][col+1]=1;
        solve(grid,row,col+1,ans,flag);
        flag[row][col+1]=0;
    } 
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
       int i,j,row,col,ans=0;
        vector<vector<int>>flag;
        vector<int>a(grid[0].size(),0);
         for( i=0;i<grid.size();i++)
        {  
            flag.push_back(a);
        }
        for( i=0;i<grid.size();i++)
        {  
            for(j=0;j<grid[0].size();j++)
            {   
                if(grid[i][j]==1)
                {
                    row=i;
                    col=j;
                }
                else if(grid[i][j]==-1)
                    flag[i][j]=1;
            }
        }
        flag[row][col]=1;
        solve(grid,row,col,ans,flag);
        return ans;
    }
};