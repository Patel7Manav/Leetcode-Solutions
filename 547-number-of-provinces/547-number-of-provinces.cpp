class Solution {
public:
    void dfs(int i,vector<bool>&vis,vector<int>adj[])
    {
        for(int j=0;j<adj[i].size();j++)
        {
            if(vis[adj[i][j]]!=true)
            {
                vis[adj[i][j]]=true;
                dfs(adj[i][j],vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
      int n=isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool>vis(n,false);
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=true)
            {   c++;
                dfs(i,vis,adj);
                vis[i]=true;
            }
        }
        return c;
    }
};