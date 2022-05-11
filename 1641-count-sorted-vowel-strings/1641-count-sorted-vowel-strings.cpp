class Solution {
public:
    int solve(vector<char>&arr,int n,int ind,int len,vector<vector<int>>&dp)
    {
        if(len==n)
        {  
            return 1;
        }
        if(dp[ind][len]!=-1)
            return dp[ind][len];
        int ans=0;
        for(int i=ind;i<5;i++)
        {
           ans+= solve(arr,n,i,len+1,dp);
        }
        return dp[ind][len]=ans;
    }
    int countVowelStrings(int n) {
        vector<char>arr;
       vector<vector<int>>dp(5,vector<int>(n+1,-1));
        arr.push_back('a');
        arr.push_back('e');
        arr.push_back('i');
        arr.push_back('o');
        arr.push_back('u');
        int ans=0;
       ans+= solve(arr,n,0,1,dp);
       ans+= solve(arr,n,1,1,dp);
       ans+= solve(arr,n,2,1,dp);
       ans+= solve(arr,n,3,1,dp);
       ans+= solve(arr,n,4,1,dp);
        return ans;
    }
};