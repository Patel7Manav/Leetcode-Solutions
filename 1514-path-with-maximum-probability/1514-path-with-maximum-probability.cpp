class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
      vector<pair<int,long double>> adj[n];
      priority_queue<pair<long double,int>>pq;
      for(int i=0;i<edges.size();i++)
      {
          adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
          adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
      }
      pq.push({1,start});
      vector<long double>dist(n,-1);
      dist[start]=1;
      while(!pq.empty())
      {
          auto t=pq.top();
          pq.pop();
         long double prob=t.first;
          int y=t.second;
          for(auto x:adj[y])
          {
             long double di=prob*x.second;
            
              if(di>dist[x.first])
              {
                  
                  dist[x.first]=di;
                  pq.push({dist[x.first],x.first});
              }

          }
      }
        if(dist[end]==-1)
            return 0;
        return dist[end];
    }
};