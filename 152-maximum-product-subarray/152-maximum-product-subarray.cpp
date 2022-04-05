class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int currmin=1,currmax=1,prod=INT_MIN;
        for(int i=0;i<n;i++)
        {   
            
            
            int temp=currmax;
            currmax=max(currmax*nums[i],max(currmin*nums[i],nums[i]));
            currmin=min(temp*nums[i],min(currmin*nums[i],nums[i]));
            prod=max(currmax,prod);
            if(nums[i]==0)
            {   
                currmin=1;
                currmax=1;
                
            }
        }
        return prod;
    }
};