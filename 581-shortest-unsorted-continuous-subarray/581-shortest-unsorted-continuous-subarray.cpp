class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>copy=nums;
        sort(copy.begin(),copy.end());
        int st=-1,end=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=copy[i])
            {
                if(st==-1)
                    st=i;
                else
                    end=i;
            }
        }
        if(st==-1)
            return 0;
        return end-st+1;
    }
};