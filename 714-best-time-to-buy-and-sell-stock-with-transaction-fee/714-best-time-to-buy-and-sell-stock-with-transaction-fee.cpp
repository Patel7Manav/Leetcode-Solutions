class Solution {
public:
     int solve(vector<int>&prices,vector<vector<int>>&dp,int n,int buy,int ind,int fee)
    {
        if(ind==n)
            return 0;
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        if(buy)
        {
            int yes=-1*prices[ind]+solve(prices,dp,n,0,ind+1,fee);
            int no=solve(prices,dp,n,1,ind+1,fee);
            return dp[ind][buy]=max(yes,no);
        }
        else
        {
            int sell=prices[ind]-fee+solve(prices,dp,n,1,ind+1,fee);
            int nosell=solve(prices,dp,n,0,ind+1,fee);
            return dp[ind][buy]=max(sell,nosell);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
         int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
       return solve(prices,dp,n,1,0,fee);
    }
};