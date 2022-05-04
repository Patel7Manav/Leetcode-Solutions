class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int c=0;
        int l=0,hi=nums.size()-1;
        while(l<hi)
        {
            if(nums[l]+nums[hi]==k)
            {
                c++;
                l++;
                hi--;
            }
            else if(nums[l]+nums[hi]<k)
            l++;
            else
                hi--;
        }
        return c;
    }
};