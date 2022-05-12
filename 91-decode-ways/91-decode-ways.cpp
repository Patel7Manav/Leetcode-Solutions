class Solution {
public:
    int solve(string s,int ind,vector<int>&dp)
    {
        if(ind>=s.length())
            return 1;
        int ans=0;
        if(dp[ind]!=-1)
            return dp[ind];
        if(ind+1<s.length() && s[ind]!='0' && s[ind]<='2')
        {   
           if((s[ind]-'0')*10+s[ind+1]-'0'<=26)
           {    
               ans+=solve(s,ind+2,dp);
           }
        }
        if(s[ind]!='0')
        {
            ans+=solve(s,ind+1,dp);
        }
        return dp[ind]=ans;
    }
    int numDecodings(string s) {
       int n=s.length()-1;
        vector<int>dp(n+1,-1);
        return solve(s,0,dp);
    }
};