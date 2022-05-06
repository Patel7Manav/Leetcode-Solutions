class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        st.push({s[0],1});
        for(int i=1;i<s.length();i++)
        {
            if(st.empty())
                st.push({s[i],1});
           else if(st.top().first==s[i])
            {
                st.top().second++;
            }
            else
                st.push({s[i],1});
            if(st.top().second==k)
            {
                st.pop();
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans=ans+string(st.top().second,st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};