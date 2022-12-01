class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>m;
        for(auto x:tasks)
            m[x]++;
        int ans=0;
        for(auto it:m)
        {
            if(it.second==1)
                return -1;
            if(it.second<=3)
                ans++;
            else if(it.second%3==0)
            {
                ans+=(it.second/3);
            }
            else if(it.second%3==1)
            {
                ans+=(it.second/3)-1+2;
            }
            else
                ans+=(it.second/3)+1;
        }
        return ans;
    }
};