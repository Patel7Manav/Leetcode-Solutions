class Solution {
public:
    string ans="";
    void solve(string s,int n)
    {
        if(n==1)
        {
            ans=s;
            return;
        }
        
        int c=1;
        string temp="";
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==s[i-1])
                c++;
            else
            {
                temp=temp+to_string(c);
                temp.push_back(s[i-1]);
                c=1;
            }
        }
        temp=temp+to_string(c);
        temp.push_back(s[s.length()-1]);
        solve(temp,n-1);
    }
    string countAndSay(int n) {
       if(n==1)
           return "1";
        solve("1",n);
        return ans;
    }
};