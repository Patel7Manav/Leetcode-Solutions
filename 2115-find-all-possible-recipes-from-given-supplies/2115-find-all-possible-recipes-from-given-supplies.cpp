class Solution {
public:
    bool dfs(string st,unordered_map<string ,vector<string>>&m,unordered_set<string>&s,unordered_set<string>&vis,unordered_set<string>&poss)
    {
        if(poss.find(st)!=poss.end())
            return true;
        if(m.find(st)!=m.end())
        {    if(vis.find(st)!=vis.end())
        {
         return false;
        }
            else
                vis.insert(st);
            for(auto x:m[st])
            {
                if(dfs(x,m,s,vis,poss)==false)
                { 
                    return false;
                }
            }
         return true;
        }
        else if(s.find(st)!=s.end())
            return true;  
        return false;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>m;
        unordered_set<string>s(supplies.begin(),supplies.end());
        int n=recipes.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<ingredients[i].size();j++)
            {
                m[recipes[i]].push_back(ingredients[i][j]);
            }
        }
        vector<string>ans;
        unordered_set<string>poss;
        for(auto x:m)
        {   bool flag=true;
         
            for(auto y:x.second)
            {   unordered_set<string>vis;
         vis.insert(x.first);
                if(dfs(y,m,s,vis,poss)==false)
                {flag=false;
                break;    
                }
            }
            if(flag==true)
            {ans.push_back(x.first);
            poss.insert(x.first);
            }
        }
        return ans;
    }
};