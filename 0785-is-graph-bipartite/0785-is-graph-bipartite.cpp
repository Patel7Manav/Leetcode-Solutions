class Solution {
public:
    bool bfs(int source, vector<vector<int>>&graph,vector<int>&vis)
    {
       queue<int>q;
        q.push(source);
        vis[source]=0;
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            for(auto x:graph[a])
            {
                if(vis[x]==-1)
                {
                    vis[x]=vis[a] ^ 1;
                    q.push(x);
                }
                else 
                {
                    if(vis[x]==vis[a])
                        return false;
                }
            }
        }
        return true; 
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=-1)
                continue;
            if(bfs(i,graph,vis)==false)
                return false;
        }
        return true;
    }
};