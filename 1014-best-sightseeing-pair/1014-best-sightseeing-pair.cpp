class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int>dp(n);
        dp[0]=values[0];
        int res=INT_MIN;
        for(int i=1;i<n;i++)
        {
            res=max(res,dp[i-1]+values[i]-i);
            dp[i]=max(dp[i-1],values[i]+i);
        }
        return res;
    }
};