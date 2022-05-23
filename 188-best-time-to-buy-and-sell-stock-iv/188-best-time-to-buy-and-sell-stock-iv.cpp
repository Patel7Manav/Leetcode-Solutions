class Solution {
public:
    int solve(vector<int>&prices,int ind,int state,int k, vector<vector<vector<int>>>&dp)
    {
        if(k==0 || ind==prices.size())
            return 0;
        if(dp[ind][state][k]!=-1)
            return dp[ind][state][k];
        if(state==0)
        {
            int buy=-prices[ind]+solve(prices,ind+1,1,k,dp);
            int nobuy=solve(prices,ind+1,0,k,dp);
            return dp[ind][state][k]=max(buy,nobuy);
        }
        else
        {
            int sell=prices[ind]+solve(prices,ind+1,0,k-1,dp);
            int nosell=solve(prices,ind+1,1,k,dp);
            return dp[ind][state][k]=max(sell,nosell);
        }
        
    }
    int maxProfit(int k, vector<int>& prices) {
       int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,0,k,dp); 
    }
};