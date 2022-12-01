class Solution {
public:
    int trapRainWater(vector<vector<int>>& hm) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int m=hm.size(),n=hm[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            pq.push({hm[i][0],{i,0}});
            pq.push({hm[i][n-1],{i,n-1}});
            vis[i][0]=1;
            vis[i][n-1]=1;
        }
        for(int i=1;i<n-1;i++)
        {
            pq.push({hm[0][i],{0,i}});
            pq.push({hm[m-1][i],{m-1,i}});
            vis[0][i]=1;
            vis[m-1][i]=1;
        }
        int water=0;
        while(!pq.empty())
        {
            auto t=pq.top();
            pq.pop();
            int val=t.first;
            int x=t.second.first,y=t.second.second;
            if(x+1<m && !vis[x+1][y])
            {
                vis[x+1][y]=1;
                if(hm[x+1][y]<=val)
                {
                    water+=(val-hm[x+1][y]);
                    pq.push({val,{x+1,y}});
                }
                else
                    pq.push({hm[x+1][y],{x+1,y}});
            }
            if(y+1<n && !vis[x][y+1])
            {
                vis[x][y+1]=1;
                if(hm[x][y+1]<=val)
                {
                    water+=(val-hm[x][y+1]);
                    pq.push({val,{x,y+1}});
                }
                else
                    pq.push({hm[x][y+1],{x,y+1}});
            }
            if(x-1>=0 && !vis[x-1][y])
            {
                vis[x-1][y]=1;
                if(hm[x-1][y]<=val)
                {
                    water+=(val-hm[x-1][y]);
                    pq.push({val,{x-1,y}});
                }
                else
                    pq.push({hm[x-1][y],{x-1,y}});
            }
            if(y-1>=0 && !vis[x][y-1])
            {
                vis[x][y-1]=1;
                if(hm[x][y-1]<=val)
                {
                    water+=(val-hm[x][y-1]);
                    pq.push({val,{x,y-1}});
                }
                else
                    pq.push({hm[x][y-1],{x,y-1}});
            }
        }
        return water;
    }
};