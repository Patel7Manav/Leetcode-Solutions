class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        vector<pair<vector<int>,vector<int>>>count;
        for(int i=0;i<words.size();i++)
        {   vector<int>countodd(26,0);
            vector<int>counteven(26,0);
            for(int j=0;j<words[i].length();j++)
            {
                if(j%2==0)
                {
                    counteven[words[i][j]-'a']++;
                }
                else
                    countodd[words[i][j]-'a']++;
            }
            count.push_back({countodd,counteven});
        }
        vector<bool>flag(words.size());
        int ans=0;
        for(int i=0;i<count.size();i++)
        {
            if(flag[i]==true)
                continue;
            for(int j=i+1;j<count.size();j++)
            {
                if(count[i].first==count[j].first && count[i].second==count[j].second)
                {
                    flag[j]=true;
                }
            }
            ans++;
        }
        return ans;
    }
};