class Solution {
public:
    bool static comp(const vector<int>& v1, const vector<int>& v2)
{
    return v1[0] < v2[0];
}
    int solve(vector<vector<int>>&arr,int ind,vector<int>&dp){
        if(ind==arr.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int i=ind+1;
        while(i<arr.size() && arr[i][0]<arr[ind][1])
        {
            i++;
        }
        int pick=arr[ind][2]+solve(arr,i,dp);
        int nopick=solve(arr,ind+1,dp);
        return dp[ind]=max(pick,nopick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
       int n=startTime.size();
        vector<vector<int>>arr(n);
        for(int i=0;i<n;i++)
        {
            arr[i].push_back(startTime[i]);
               arr[i].push_back(endTime[i]);
               arr[i].push_back(profit[i]);
        }
        sort(arr.begin(),arr.end(),comp);
        vector<int>dp(n+1,-1);
        return solve(arr,0,dp);
    }
};