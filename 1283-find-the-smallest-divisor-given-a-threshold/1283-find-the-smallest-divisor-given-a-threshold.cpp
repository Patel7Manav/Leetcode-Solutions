class Solution {
public:
    bool isvalid(int m,vector<int>nums,int t,int n)
    {   int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+ceil(float(nums[i])/m);
            if(sum>t)
                return false;
        }
  
      return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int mn=1,mx=0;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,nums[i]);
        }
        int ans=0;
        while(mn<=mx)
        {
            int mid=mn+(mx-mn)/2;
            if(isvalid(mid,nums,threshold,n))
            {
                ans=mid;
                mx=mid-1;
            }
            else
                mn=mid+1;
        }
        return ans;
    }
};