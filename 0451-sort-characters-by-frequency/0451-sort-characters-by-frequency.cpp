class Solution {
public:
    string frequencySort(string s) {
      unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        priority_queue<pair<int,char>>p;
        for(auto it:m)
        {
            p.push({it.second,it.first});
        }
        string ans="";
        while(!p.empty())
        {   
            ans+=string(p.top().first, p.top().second);
            p.pop();
        }
        return ans;
    }
};