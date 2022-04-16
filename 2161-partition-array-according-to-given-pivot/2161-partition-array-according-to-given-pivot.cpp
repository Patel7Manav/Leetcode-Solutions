class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       vector<int>sm;
        vector<int>lar;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
            {
                sm.push_back(nums[i]);
            }
            else if(nums[i]>pivot)
                lar.push_back(nums[i]);
            else
                count++;
        }
        int i=0;
        for( i=0;i<sm.size();i++)
        {
            nums[i]=sm[i];
        }
        while(count--)
        {
            nums[i++]=pivot;
        }
        for(int j=0;j<lar.size();j++)
            nums[j+i]=lar[j];
        return nums;
    }
};