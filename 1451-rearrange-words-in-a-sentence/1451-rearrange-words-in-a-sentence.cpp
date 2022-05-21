class Solution {
public:
    string arrangeWords(string text) {
        map<int,string>m;
       int mx=0;
        for(int i=0;i<text.length();)
        {
            int j=i;string curr="";
            while(j<text.length()&& text[j]!=' ')
            {
                curr=curr+text[j];
                j++;
            }
            curr[0]=tolower(curr[0]);
            m[j-i]+=(curr)+" ";
            mx=max(mx,j-i);
            i=j+1;
            
        }
       
        string ans="";
        for(auto x:m)
        {
            ans=ans+x.second;
        }
        ans[0]=toupper(ans[0]);
        ans.pop_back();
        
        return ans;
    }
};