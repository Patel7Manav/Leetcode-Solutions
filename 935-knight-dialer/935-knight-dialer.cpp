class Solution {
public:
    int solve(vector<vector<int>>&mat,int i,int j,int n,vector<vector<vector<int>>>&dp)
    {
        if(i<0 || i>3 || j<0 || j>2 || mat[i][j]==-1)
            return 0;
        if(n==0)
            return 1;
        if(dp[i][j][n]!=-1)
            return dp[i][j][n];
        int one=solve(mat,i-2,j-1,n-1,dp)%1000000007;
        int two=solve(mat,i-2,j+1,n-1,dp)%1000000007;
        int three=solve(mat,i-1,j-2,n-1,dp)%1000000007;
        int four=solve(mat,i-1,j+2,n-1,dp)%1000000007;
        int five=solve(mat,i+1,j-2,n-1,dp)%1000000007;
        int six=solve(mat,i+1,j+2,n-1,dp)%1000000007;
        int seven=solve(mat,i+2,j-1,n-1,dp)%1000000007;
        int eight=solve(mat,i+2,j+1,n-1,dp)%1000000007;
        return dp[i][j][n]=(((((((one%1000000007+two%1000000007)%1000000007+three%1000000007)%1000000007+four%1000000007)%1000000007+five%1000000007)%1000000007+six%1000000007)%1000000007+seven%1000000007)%1000000007+eight%1000000007)%1000000007;
    }
    int knightDialer(int n) {
        vector<vector<int>>mat;
        mat.push_back({1,2,3});
    mat.push_back({4,5,6});
    mat.push_back({7,8,9});
    mat.push_back({-1,0,-1});
    long long ans=0;
        vector<vector<vector<int>>>dp(4,vector<vector<int>>(3,vector<int>(n+1,-1)));
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
         if(mat[i][j]!=-1)
             ans+=solve(mat,i,j,n-1,dp);
        }
    }
        return ans%1000000007;
    }
};