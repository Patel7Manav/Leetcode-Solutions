class Solution {
public:
    pair<int,int> dfs(vector<int>adj[],vector<int>&vis,int i,vector<int>&quiet)
    {

        vis[i]=1;
        int val=quiet[i];
       
        pair<int,int> ans={val,i};
        for(auto x:adj[i])
        {
        
            if(!vis[x])
            {
                auto tmp=dfs(adj,vis,x,quiet);
                if(tmp.first<ans.first)
                { 
                    ans=tmp;
                }
            }
        }
        return ans;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
       int n=quiet.size();
       vector<int>adj[n];
       for(int i=0; i<richer.size();i++)
           adj[richer[i][1]].push_back(richer[i][0]);
       vector<int>sol(n,0);
        for(int i=0;i<n;i++)
        {
           int val=quiet[i];
           vector<int>vis(n,0);
            pair<int,int>ans={val,i};
           auto tmp=dfs(adj,vis,i,quiet);
                if(tmp.first<val)
                 ans=tmp;   
            sol[i]=ans.second;
        }
        return sol;
    }
};