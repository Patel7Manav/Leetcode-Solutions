class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&mat,int val,vector<vector<int>>&dp)
    {
        if(i>=mat.size() || i<0 || j>=mat[0].size() || j<0 ||  mat[i][j]<=val)
            return 0;
          
            if(dp[i][j]!=-1)
            {   
                return dp[i][j];
            }
        
        int left=0,right=0,top=0,down=0;
       
        left=solve(i-1,j,mat,mat[i][j],dp);
        right=solve(i+1,j,mat,mat[i][j],dp);
        down=solve(i,j+1,mat,mat[i][j],dp);
        top=solve(i,j-1,mat,mat[i][j],dp);
        
        return dp[i][j]=1+max(max(max(left,right),top),down);
    
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
     int m=matrix.size(),n=matrix[0].size(),ans=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {   
                ans=max(ans,solve(i,j,matrix,-1,dp));
            }
        }
        return ans;
    }
};