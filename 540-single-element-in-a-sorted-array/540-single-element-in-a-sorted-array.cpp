class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo=0,hi=nums.size()-1;
        if(hi==0)
            return nums[hi];
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if((mid==0 && nums[mid]!=nums[mid+1]) || (mid==nums.size()-1 && nums[mid]!=nums[mid-1]) || (nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]))
            {
                return nums[mid];
            }
            else if(mid%2!=0)
            {
                if(nums[mid]==nums[mid-1])
                lo=mid+1;
                else
                    hi=mid-1;
            }
            else
            {
                if(nums[mid]==nums[mid-1])
                hi=mid-1;
                else
                    lo=mid+1;
            }
        }
       return 0; 
    }
};