class Solution {
public:
    int solve(vector<int>&nums,int target,int ind)
    {
        if(ind==nums.size())
        {
            if(target==0)
                return 1;
            else
                return 0;
        }
        int add=solve(nums,target-nums[ind],ind+1);
        int sub=solve(nums,target+nums[ind],ind+1);
        return add+sub;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0);
    }
};