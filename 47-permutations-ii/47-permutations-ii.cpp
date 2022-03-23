class Solution {
public:
     set<vector<int>>ans;
   void solve(vector<int>nums,int l,int r)
    {
        if(l==r)
        {
            ans.insert(nums);
            return;
        }
         for(int i=l;i<=r;i++)
         {
             swap(nums[i],nums[l]);
             solve(nums,l+1,r);
             swap(nums[i],nums[l]);
         }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums,0,nums.size()-1);
        vector<vector<int>>sol;
        for(auto x:ans)
        {
            sol.push_back(x);
        }
        return sol;
    }
};