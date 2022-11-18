class Solution {
public:
    bool dfs(int source, vector<int>&vis,vector<int>adj[])
    {
        vis[source]=2;
        for(auto x:adj[source])
        {
            if(!vis[x])
            {
                if(dfs(x,vis,adj))
                    return true;
            }
            else if(vis[x]==2)
                return true;
        }
        vis[source]=1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pr) {
        vector<int>adj[numCourses];
        int n=pr.size();
        for(int i=0;i<n;i++)
        {
            adj[pr[i][1]].push_back(pr[i][0]);
        }
        vector<int>vis(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,adj))
                    return false;
            }
        }
        return true;
    }
};