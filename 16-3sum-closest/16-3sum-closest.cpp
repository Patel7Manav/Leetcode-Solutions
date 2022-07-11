class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
        int diff=INT_MAX,res=0;
        for(int i=0;i<nums.size()-2;i++)
        {
            int l=i+1,h=nums.size()-1,curr=0;
            while(l<h)
            {
               curr=nums[i]+nums[l]+nums[h];
                if(abs(target-curr)<diff)
                {   diff=abs(target-curr);
                    res=curr;
                 }
               else 
               {if(curr>target)
                   h--;
                else
                    l++;
               }
            }
        }
        return res;
    }
};