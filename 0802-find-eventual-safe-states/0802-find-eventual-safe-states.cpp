class Solution {
public:
    bool dfs(int i,vector<int>&vis,vector<int>&pvis,vector<int>&check,vector<vector<int>>&graph)
    {   vis[i]=1;
        pvis[i]=1;
        check[i]=0;
        for(auto x:graph[i])
        {
            if(!vis[x])
            {
                if(dfs(x,vis,pvis,check,graph)==false)
                    return false;
            }
            else if(pvis[x]==1)
                return false;
        }
     pvis[i]=0;
     check[i]=1;
     return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0),pvis(n,0);
        vector<int>check(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,pvis,check,graph);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(check[i]==1)
                ans.push_back(i);
        }
        return ans;
    }
};