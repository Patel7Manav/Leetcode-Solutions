class Solution {
public:
    int solve(vector<int>&coins,int amount,int ind,vector<vector<int>>&dp)
    {
        if(ind==coins.size())
        {
            if(amount==0)
                return 1;
            else
                return 0;
        }
        if(dp[amount][ind]!=-1)
            return dp[amount][ind];
        int pick=0;
        if(coins[ind]<=amount)
         pick=solve(coins,amount-coins[ind],ind,dp);
        int nopick=solve(coins,amount,ind+1,dp);
        return dp[amount][ind]=pick+nopick;
    }
    int change(int amount, vector<int>& coins) {
      vector<vector<int>>dp(amount+1,vector<int>(coins.size(),-1));
        return solve(coins,amount,0,dp); 
    }
};