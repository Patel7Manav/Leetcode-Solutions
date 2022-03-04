class Solution {
public:
   static bool comp(pair<int,int>a,pair<int,int>b)
    {
        if(a.first==b.first)
            return a.second<b.second;
       return a.first>b.first;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<pair<int,int>>p;
        for(int i=0;i<people.size();i++)
        {
           p.push_back({people[i][0],people[i][1]}); 
            people[i][0]=0;
            people[i][1]=0;
        }
        sort(p.begin(),p.end(),comp);
        int mx=-1;
        for(int i=0;i<p.size();i++)
        {
            if(people[p[i].second][0]==0)
            {people[p[i].second][0]=p[i].first;
            people[p[i].second][1]=p[i].second;
            mx=max(mx,p[i].second);}
            else
            {
                for(int j=mx;j>=p[i].second;j--)
                {
                    people[j+1][0]=people[j][0];
                    people[j+1][1]=people[j][1];
                }
                people[p[i].second][0]=p[i].first;
            people[p[i].second][1]=p[i].second;
                mx=mx+1;
            }
        }
        return people;
    }
};