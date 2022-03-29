class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo=0,hi=nums.size()-1;
        int n=nums.size()-1;
        if(n==0)
            return 0;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(mid==0)
            {
                if(nums[mid]>nums[mid+1])
                    return mid;
                else
                    lo=mid+1;
            }
            else if(mid==n)
            {
                if(nums[mid]>nums[mid-1])
                    return mid;
                else
                    hi=mid-1;
            }
            else if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid]<nums[mid-1])
                hi=mid-1;
            else 
                lo=mid+1;
        }
        return -1;
    }
};