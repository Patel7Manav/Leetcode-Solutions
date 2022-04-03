class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       /* int n=nums.size();
        bool flag=false;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                flag=true;
                break;
            }
        }*/
        next_permutation(nums.begin(),nums.end());
    }
};