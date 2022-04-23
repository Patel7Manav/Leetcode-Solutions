class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<pair<int,string>,int>mp;
        set<string>s1;
        set<int>s2;
         for(int i=0;i<orders.size();i++)
        {
           s1.insert(orders[i][2]);
             s2.insert(stoi(orders[i][1]));
        }
        
        for(auto x:s1)
        {
            for(auto y:s2)
            {
                mp[{y,x}]=0;
            }
        }
        for(int i=0;i<orders.size();i++)
        {
            mp[{stoi(orders[i][1]),orders[i][2]}]++;
        }
        vector<string>a;
        vector<vector<string>>ans;
        a.push_back("Table");
        for(auto x:s1)
            a.push_back(x);
        ans.push_back(a);
        for(auto x = mp.begin(); x != mp.end();)
        {
            vector<string>a;
            a.push_back(to_string(x->first.first));
            int val=x->first.first;
                while(x!=mp.end() && x->first.first==val){
            a.push_back(to_string(x->second));
                    x++;
                    }
            ans.push_back(a);
        }
        return ans;
    }
};