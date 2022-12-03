class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
      int m=maze.size(),n=maze[0].size();
      vector<vector<int>>vis(m,vector<int>(n,0));
        vis[entrance[0]][entrance[1]]=1;
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        int ans=0;
        while(!q.empty())
        {
            int si=q.size();
            for(int i=0;i<si;i++)
            {
             auto t=q.front();
                q.pop();
             int x=t.first,y=t.second;
            if((x==0 || y==0 || x==m-1 || y==n-1) && !(x==entrance[0] && y==entrance[1]))
                return ans;
             if(x+1<m && maze[x+1][y]!='+' && !vis[x+1][y])
             {
                 q.push({x+1,y});
                 vis[x+1][y]=1;
             }
            if(y+1<n && maze[x][y+1]!='+' && !vis[x][y+1])
             {
                 q.push({x,y+1});
                 vis[x][y+1]=1;
             }
             if(x-1>=0 && maze[x-1][y]!='+' && !vis[x-1][y])
             {
                 q.push({x-1,y});
                 vis[x-1][y]=1;
             }
            if(y-1>=0 && maze[x][y-1]!='+' && !vis[x][y-1])
             {
                 q.push({x,y-1});
                 vis[x][y-1]=1;
             }
            }
            ans++;
        }
        return -1;
    }
};