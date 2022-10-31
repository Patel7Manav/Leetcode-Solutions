class Solution {
public:
    bool ischeck(vector<int>&nums,int m,int target)
    {
        int sum=0;
        for(int i=0;i<m;i++)
        {
            sum+=nums[i];
            if(sum>=target)
                return true;
        }
        for(int i=m;i<nums.size();i++)
        {
            sum+=nums[i];
            sum-=nums[i-m];
            if(sum>=target)
                return true;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=1,h=nums.size(),ans=0;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(ischeck(nums,m,target))
            {
                ans=m;
                h=m-1;
            }
            else
                l=m+1;
        }
        return ans;
    }
};