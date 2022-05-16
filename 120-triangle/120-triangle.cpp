class Solution {
public:
   int solve(vector<vector<int>>&triangle,int row,int ind,vector<vector<int>>&dp)
    {
        if(row==triangle.size())
            return 0;
       if(dp[row][ind]!=-1)
           return dp[row][ind];
        int right=1e8;
        int left=triangle[row][ind]+solve(triangle,row+1,ind,dp);
        if(ind+1<triangle[row].size())
         right=triangle[row][ind+1]+solve(triangle,row+1,ind+1,dp);
        return dp[row][ind]=min(left,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
       int n=triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(triangle,1,0,dp)+triangle[0][0];
    }
};