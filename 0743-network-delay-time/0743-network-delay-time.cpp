class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>ans(n+1,INT_MAX);
        queue<int>q;
        q.push(k);
        ans[k]=0;
        while(!q.empty())
        {
            
            int a=q.front();
            q.pop();

            for(auto x:adj[a])
            {
                if(ans[x.first]>ans[a]+x.second)
                {   ans[x.first]=ans[a]+x.second;
                    q.push(x.first);
                
                }
            }
        }
        int res=0;
        for(int i=1;i<=n;i++)
        {
            if(ans[i]==INT_MAX)
                return -1;
            res=max(ans[i],res);
        }
        return res;
    }
};