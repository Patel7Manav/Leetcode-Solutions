/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> emp, int id) {
        int n=emp.size();
        vector<int>adj[2001];
        vector<int>imp(2001);
        for(int i=0;i<n;i++)
        {
            imp[emp[i]->id]=emp[i]->importance;
            for(int j=0;j<emp[i]->subordinates.size();j++)
            {
                adj[emp[i]->id].push_back(emp[i]->subordinates[j]);
            }
        }
        queue<int>q;
        q.push(id);
        int ans=0;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            ans+=imp[temp];
            for(auto x:adj[temp])
            {
                q.push(x);
            }
        }
        return ans;
    }
};