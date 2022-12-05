class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        pq.push({INT_MAX,1});
        vector<int>dis(n+1,INT_MAX);
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            int di=temp.first,node=temp.second;
            
            for(auto x:adj[node])
            {
                if(min(di,x.second)<dis[x.first])
                {
                    dis[x.first]=min(di,x.second);
                    pq.push({dis[x.first],x.first});
                }
            }
        }
        return dis[n];
    }
};