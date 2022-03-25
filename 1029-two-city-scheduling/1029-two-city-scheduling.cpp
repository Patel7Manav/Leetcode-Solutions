class Solution {
public:
      static  bool comp(const pair<int,int>&x, const pair<int,int> &y)
        {
            return x.second-x.first>y.second-y.first;
        }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int>>p;
        for(int i=0;i<costs.size();i++)
        {
            p.push_back(make_pair(costs[i][0],costs[i][1]));
        }
        sort(p.begin(),p.end(),comp);
        int n=costs.size()/2,sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=p[i].first;
            sum+=p[n+i].second;
        }
        return  sum;
    }
};