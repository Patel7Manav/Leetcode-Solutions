class Solution {
public:
    int solve(vector<int>&prices,int ind,int action,int transac,vector<vector<vector<int>>>&dp)
    {
          if(transac==2)
              return 0;
        if(ind>=prices.size())
            return 0;
        if(dp[ind][action][transac]!=-1)
            return dp[ind][action][transac];
        if(action==0)
        {
            int left=0-prices[ind]+solve(prices,ind+1,1,transac,dp);
            int right=solve(prices,ind+1,0,transac,dp);
            return dp[ind][action][transac]=max(left,right);
        }
        else {
            int left=prices[ind]+solve(prices,ind+1,0,transac+1,dp);
            int right=solve(prices,ind+1,1,transac,dp);
            return dp[ind][action][transac]=max(left,right);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        int profit= solve(prices,0,0,0,dp);  
        if(profit<=0)
            return 0;
        return profit;
    }
};