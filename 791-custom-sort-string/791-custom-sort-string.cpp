class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>count(26,0);
        for(int i=0;i<s.length();i++)
        {
            count[s[i]-'a']++;
        }
        string ans="";
        for(int i=0;i<order.length();i++)
        {
            for(int j=0;j<count[order[i]-'a'];j++)
            {
                ans+=order[i];
            }
            count[order[i]-'a']=0;
        }
        for(int i=0;i<26;i++)
        {
            if(count[i]!=0)
            {
                ans+=string(count[i],'a'+i);
            }
        }
        return ans;
    }
};