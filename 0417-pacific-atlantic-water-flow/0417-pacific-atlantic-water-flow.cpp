class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       vector<vector<int>>ans;
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
       set<pair<int,int>>s;
        for(int i=0;i<m;i++)
        {
            q.push({i,0});
            s.insert({i,0});
            vis[i][0]=1;
        }
        for(int i=0;i<n;i++)
        {
            q.push({0,i});
            s.insert({0,i});
            vis[0][i]=1;
        }
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            int x=t.first,y=t.second;
            if(x+1<m && heights[x+1][y]>=heights[x][y] && !vis[x+1][y])
            {
                q.push({x+1,y});
                s.insert({x+1,y});
                vis[x+1][y]=1;
            }
            if(x-1>=0 && heights[x-1][y]>=heights[x][y] && !vis[x-1][y])
            {
                q.push({x-1,y});
                s.insert({x-1,y});
                vis[x-1][y]=1;
            }
            if(y+1<n && heights[x][y+1]>=heights[x][y] && !vis[x][y+1])
            {
                q.push({x,y+1});
                s.insert({x,y+1});
                vis[x][y+1]=1;
            }
            if(y-1>=0 && heights[x][y-1]>=heights[x][y] && !vis[x][y-1])
            {
                q.push({x,y-1});
                s.insert({x,y-1});
                vis[x][y-1]=1;
            }
        }
        fill(vis.begin(),vis.end(),vector<int>(n,0));
         for(int i=0;i<m;i++)
        {
            q.push({i,n-1});
            vis[i][n-1]=1;
        }
        for(int i=0;i<n;i++)
        {
            q.push({m-1,i});
            vis[m-1][i]=1;
        }
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            int x=t.first,y=t.second;
            if(s.find(t)!=s.end())
            {
                ans.push_back({x,y});
                s.erase(t);
            }
            if(x+1<m && heights[x+1][y]>=heights[x][y] && !vis[x+1][y])
            {
                q.push({x+1,y});
                vis[x+1][y]=1;
            }
            if(x-1>=0 && heights[x-1][y]>=heights[x][y] && !vis[x-1][y])
            {
                q.push({x-1,y});
                vis[x-1][y]=1;
            }
            if(y+1<n && heights[x][y+1]>=heights[x][y] && !vis[x][y+1])
            {
                q.push({x,y+1});
                vis[x][y+1]=1;
            }
            if(y-1>=0 && heights[x][y-1]>=heights[x][y]  && !vis[x][y-1])
            {
                q.push({x,y-1});
                vis[x][y-1]=1;
            }
        }
        return ans;
    }
};