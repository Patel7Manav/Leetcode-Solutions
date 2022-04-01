class Solution {
public:
    int solve(vector<int>cost,vector<int>&dp,int n)
    {
        if(n<=1)
            return cost[n];
        if(dp[n]!=-1)
            return dp[n];
        int one=cost[n]+solve(cost,dp,n-1);
        int two=cost[n]+solve(cost,dp,n-2);
        return dp[n]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
      int n=cost.size();
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return min(solve(cost,dp1,n-1),solve(cost,dp2,n-2));
    }
};