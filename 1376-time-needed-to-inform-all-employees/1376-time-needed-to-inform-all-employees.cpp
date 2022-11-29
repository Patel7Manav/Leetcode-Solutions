class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& iT) {
     if(n==1)
         return 0;
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
           if(i!=headID)
            adj[manager[i]].push_back(i); 
        }
        queue<pair<int,int>>q;
        q.push({headID,iT[headID]});
        int ans=0;
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            int a=t.first,ti=t.second;
            ans=max(ans,ti);
            for(auto x:adj[a])
            {
                q.push({x,iT[x]+ti});
            }
        }
        return ans;
    }
};