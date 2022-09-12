class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int m=grid.size(),n=grid[0].size();
        bool flag=false;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    flag=true;
            }
        }
        if(flag==false)
            return 0;
        if(q.empty())
            return -1;
        int ans=-1;
        while(!q.empty())
        {   ans++;
            int si=q.size();
            for(int i=0;i<si;i++)
            {
                pair<int,int>p=q.front();
                int x=p.first,y=p.second;
                q.pop();
                if(x-1>=0 && grid[x-1][y]==1)
                {
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                }
                if(x+1<m && grid[x+1][y]==1)
                {
                    grid[x+1][y]=2;
                    q.push({x+1,y});
                }
                if(y-1>=0 && grid[x][y-1]==1)
                {
                    grid[x][y-1]=2;
                    q.push({x,y-1});
                }
                if(y+1<n && grid[x][y+1]==1)
                {
                    grid[x][y+1]=2;
                    q.push({x,y+1});
                }
            }
        }
     
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return ans;
        
    }
};