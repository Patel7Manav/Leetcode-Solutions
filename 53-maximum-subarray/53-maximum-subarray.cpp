class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int mx=nums[0],curr=0;
        for(int i=0;i<nums.size();i++)
       {
           curr=curr+nums[i];
            mx=max(mx,curr);
            if(curr<0)
                curr=0;
       }
        return mx;
    }
};