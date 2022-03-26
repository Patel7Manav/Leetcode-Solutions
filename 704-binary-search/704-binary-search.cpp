class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;
        while(lo<=hi)
        {
            int mi=lo+(hi-lo)/2;
            if(nums[mi]==target)
                return mi;
            else if(nums[mi]>target)
                hi=mi-1;
            else
                lo=mi+1;
        }
        return -1;
    }
};