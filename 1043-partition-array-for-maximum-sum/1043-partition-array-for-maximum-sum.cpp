class Solution {
public:
    int solve(vector<int>&arr,int ind,int k,vector<int>&dp)
    {
        if(ind>=arr.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int mx=INT_MIN,ans=0,sum=0;
        for(int i=ind;i<ind+k && i<arr.size();i++)
        {
            mx=max(mx,arr[i]);
            ans=mx*(i-ind+1)+solve(arr,i+1,k,dp);
            sum=max(sum,ans);
        }
        return dp[ind]=sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       vector<int>dp(arr.size()+1,-1);
        return solve(arr,0,k,dp); 
    }
};