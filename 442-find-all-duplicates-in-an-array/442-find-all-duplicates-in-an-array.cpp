class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<bool>arr(n+1);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(arr[nums[i]])
                ans.push_back(nums[i]);
            else
                arr[nums[i]]=true;
        }
        return ans;
    }
};