class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       map<int,int>m;
        for(auto x:arr)
            m[x]++;
        set<int>s;
        for(auto it:m)
            if(s.find(it.second)!=s.end())
                return false;
        else
            s.insert(it.second);
        return true;
    }
};