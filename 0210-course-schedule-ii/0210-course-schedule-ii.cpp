class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pr) {
        if(numCourses==1)
            return {0};
        vector<int> adj[numCourses];
        vector<int>indeg(numCourses,0);
        for(int i=0;i<pr.size();i++)
        {
            adj[pr[i][0]].push_back(pr[i][1]);
            indeg[pr[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(auto x:adj[temp])
            {
                indeg[x]--;
                if(indeg[x]==0)
                    q.push(x);
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==numCourses)
            return ans;
        return {};
    }
};