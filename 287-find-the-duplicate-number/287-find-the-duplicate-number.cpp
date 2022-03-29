class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int n=nums.size();
        vector<int>arr(n,0);
        for(int i=0;i<n;i++)
        {
            arr[nums[i]]++;
        }
        int t=*max_element(arr.begin(),arr.end());
        auto it=find(arr.begin(),arr.end(),t);
        return it-arr.begin();
    }
};