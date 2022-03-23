class Solution {
public:
        void subset(vector<vector<int>>&ans,vector<int>&a,vector<int>nums,int ind,int n){
                ans.push_back(a);
            for(int i=ind;i<n;i++)
            {
                if(i!=ind && nums[i]==nums[i-1])
                    continue;
                
                    a.push_back(nums[i]);
                    subset(ans,a,nums,i+1,n);
                    a.pop_back();
            }
        }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>>ans;
        vector<int>a;
        sort(nums.begin(),nums.end());
        subset(ans,a,nums,0,nums.size());
        return ans;
    }
};