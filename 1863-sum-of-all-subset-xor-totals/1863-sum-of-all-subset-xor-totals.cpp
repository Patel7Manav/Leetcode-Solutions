class Solution {
public:
    int findsum(vector<int>&nums, int level,int currxor)
    {
        if(level==nums.size())
            return currxor;
        int inc=findsum(nums,level+1,currxor^nums[level]);
        int exc=findsum(nums,level+1,currxor);
        return inc+exc;
        
    }
    int subsetXORSum(vector<int>& nums) {
       return findsum(nums,0,0);
    }
};