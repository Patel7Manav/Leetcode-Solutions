class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
      queue<pair<int,int>>q;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),-1));
        bool flag1=false, flag2=false;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            if(grid[i][j]==1)
            { q.push({i,j});
             vis[i][j]=0;
             flag1=true;
            }
            else
                flag2=true;
        }
    }
        if(flag1==false || flag2==false)
            return -1;
        int ans=-1;
        while(!q.empty())
        {   ans++;
            int si=q.size();
            for(int x=0;x<si;x++)
            {
                pair<int,int>p=q.front();
                q.pop();
                int i=p.first,j=p.second;
                if(i-1>=0 && vis[i-1][j]!=0)
                {q.push({i-1,j});
                 vis[i-1][j]=0;
                }
                if(i+1<grid.size() && vis[i+1][j]!=0)
                { q.push({i+1,j});
                vis[i+1][j]=0;}
                if(j-1>=0 && vis[i][j-1]!=0)
                {q.push({i,j-1});
                vis[i][j-1]=0;}
                if(j+1<grid[0].size() && vis[i][j+1]!=0)
                { q.push({i,j+1});
                vis[i][j+1]=0;}
            }
        }
        return ans;
    }
};