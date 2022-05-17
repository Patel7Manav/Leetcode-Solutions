class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res=1,n=nums.size(),curr=nums[0];
        for(int i=1;i<n;)
        {
            if(nums[i]>curr)
            {
                int j=i+1;
                while(j<n && nums[j]>=nums[j-1])
                {
                    j++;
                }
                res++;
                curr=nums[j-1];
                i=j;
            }
            else if(nums[i]<curr)
            {
                int j=i+1;
                while(j<n && nums[j]<=nums[j-1])
                {
                    j++;
                }
                res++;
                curr=nums[j-1];
                i=j;
            }
            else
                i++;
        }
        return res;
    }
};