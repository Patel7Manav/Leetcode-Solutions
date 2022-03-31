class Solution {
public:
    bool isvalid(int mid,vector<int>&nums,int m,int n)
    {   int curr=0,mx=0,c=0;
        for(int i=0;i<n;i++)
        {   mx=max(mx,curr);
            if((curr+nums[i])<=mid)
            {
                curr+=nums[i];
            }
            else
            {   
                curr=nums[i];
                c++;
            }
        }
        c++;
     if(c<=m && mid>=mx)
         return true;
     return false;
        
    }
    int splitArray(vector<int>& nums, int m) {
        int mn=INT_MAX,mx=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            mx+=nums[i];
            mn=min(mn,nums[i]);
        }
        int ans=0;
        while(mn<=mx)
        {
            int mid=mn+(mx-mn)/2;
            if(isvalid(mid,nums,m,n))
            {
                ans=mid;
                mx=mid-1;
            }
            else
            {
                mn=mid+1;
            }
        }
        return ans;
    }
};