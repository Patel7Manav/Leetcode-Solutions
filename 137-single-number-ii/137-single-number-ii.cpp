class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();)
        {
            int j=i+1,c=1;
            while(j<nums.size() && nums[j]==nums[i])
            {
                c++;
                j++;
            }
            if(c!=3)
                return nums[i];
            i=j;
        }
        return 0;
    }
};