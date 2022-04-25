class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp;
        set<int>s;
        for(int i=0;i<matches.size();i++)
        {
            mp[matches[i][1]]++;
            s.insert(matches[i][0]);
        }
        vector<int>a;
        for(auto x:s)
        {
            if(mp.find(x)==mp.end())
                a.push_back(x);
        }
        vector<vector<int>>ans;
        ans.push_back(a);
        vector<int>b;
        for(auto itr:mp)
        {
            if(itr.second==1)
                b.push_back(itr.first);
        }
        ans.push_back(b);
        return ans;
    }
};