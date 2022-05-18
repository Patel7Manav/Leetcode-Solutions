class Solution {
public:
    int solve(vector<vector<int>>&pairs,int ind,int last,vector<vector<int>>&dp)
    {
        if(ind==pairs.size())
            return 0;
        if(dp[ind][last+1001]!=-1)
            return dp[ind][last+1001];
        int pick=0;
        if(pairs[ind][0]>last)
            pick=1+solve(pairs,ind+1,pairs[ind][1],dp);
        int nopick=solve(pairs,ind+1,last,dp);
        return dp[ind][last+1001]=max(pick,nopick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
       sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<vector<int>>dp(n+1,vector<int>(2002,-1));
        return solve(pairs,0,-1001,dp);
    }
};