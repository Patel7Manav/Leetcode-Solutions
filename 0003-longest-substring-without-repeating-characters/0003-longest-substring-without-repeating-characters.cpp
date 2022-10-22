class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,j,last=-1;
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        {
                if(m.find(s[i])!=m.end())
                {
                 ans=max(ans,i-last-1);
                    last=max(last,m[s[i]]);
                    m[s[i]]=i;
                cout<<ans<<" ";
                }
                else
                    m[s[i]]=i;
        }
        int lo=s.length()-last-1;
        ans=max(ans,lo);
        return ans;
    }
};