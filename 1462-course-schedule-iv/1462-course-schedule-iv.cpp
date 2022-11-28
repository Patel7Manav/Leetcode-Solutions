class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& pr, vector<vector<int>>& queries) {
        if(pr.size()==0)
        {
            vector<bool>sol(queries.size(),false);
            return sol;
        }
        vector<int> adj[numCourses];
        for(int i=0;i<pr.size();i++)
        {
            adj[pr[i][1]].push_back(pr[i][0]);
        }
        vector<unordered_set<int>>rel(numCourses);
        
       for(int i=0;i<numCourses;i++)
       {  
           queue<int>q;
        vector<int>vis(numCourses,0);
        vis[i]=1;
           for(auto x:adj[i])
           {
               q.push(x);
               vis[x]=1;
           }
           while(!q.empty())
           {
               auto temp=q.front();
               q.pop();
               rel[i].insert(temp);
               for(auto y:adj[temp])
               {    if(!vis[y])
               {q.push(y);
               vis[y]=1;
               }
               }
           }
       } 
        int si=queries.size();
        vector<bool>sol(si);
        for(int i=0;i<queries.size();i++)
        {
            int u=queries[i][0],v=queries[i][1],lvlu,lvlv;
            if(rel[v].find(u)!=rel[v].end())
                sol[i]=true;
        }
        return sol;
    }
};