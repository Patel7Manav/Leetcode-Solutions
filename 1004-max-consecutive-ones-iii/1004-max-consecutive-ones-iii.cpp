class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,count=0,curr=0,mx=0,n=nums.size();
        while(j<n)
        {
            if(nums[j]==0)
                count++;
            if(count>k)
            {
                while(count>k)
                {
                    if(nums[i]==0)
                    {
                        count--;
                    }
                     curr--;
                    i++;
                }
            }
             curr++;
            mx=max(mx,curr);
            j++;
        }
        return mx;
    }
};