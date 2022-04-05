class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size(),curr=0,linsum=INT_MIN,totsum=0;
        for(int i=0;i<n;i++)
        {
            curr+=nums[i];
            linsum=max(linsum,curr);
            if(curr<0)
                curr=0;
            totsum+=nums[i];
            nums[i]=nums[i]*-1;
        }
        int minsum=INT_MIN;
        curr=0;
        for(int i=0;i<n;i++)
        {
            curr+=nums[i];
            minsum=max(minsum,curr);
            if(curr<0)
                curr=0;
        }
        minsum=minsum*-1;
        if(totsum==minsum)
            return linsum;
        int circsum=totsum-minsum;
        return max(linsum,circsum);
    }
};