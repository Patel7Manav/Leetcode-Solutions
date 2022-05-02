class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0,hi=nums.size()-1;
        while(l<hi)
        {
            if(nums[l]%2==1 && nums[hi]%2==0)
            {
                swap(nums[l++],nums[hi--]);
            }
            else
            {
                if(nums[l]%2==0)
                    l++;
                if(nums[hi]%2==1)
                    hi--;
            }
        }
        return nums;
    }
};