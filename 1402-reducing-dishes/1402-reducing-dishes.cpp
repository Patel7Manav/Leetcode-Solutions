class Solution {
public:
    
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int time=1;time<=n;time++)
            {
               
                int pick=satisfaction[ind]*time+dp[ind+1][time+1];
                int nopick=dp[ind+1][time];
                dp[ind][time]=max(pick,nopick);
            }
        }
        
      return dp[0][1];
    }
};