class Solution {
public:
    int solve(vector<char>&arr,int n,string curr,int ind,int len,vector<vector<int>>&dp)
    {
        if(len==n)
        {   cout<<curr<<" ";
            return 1;
        }
        if(dp[ind][len]!=-1)
            return dp[ind][len];
        int ans=0;
        for(int i=ind;i<5;i++)
        {
           ans+= solve(arr,n,curr+arr[i],i,len+1,dp);
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
       ans+= solve(arr,n,"a",0,1,dp);
       ans+= solve(arr,n,"e",1,1,dp);
       ans+= solve(arr,n,"i",2,1,dp);
       ans+= solve(arr,n,"o",3,1,dp);
       ans+= solve(arr,n,"u",4,1,dp);
        return ans;
    }
};