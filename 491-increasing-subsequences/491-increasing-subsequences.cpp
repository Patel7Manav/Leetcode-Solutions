class Solution {
public:
    void solve(int ind,set<vector<int>>&ans,vector<int>&a,vector<int>nums,int curr)
    {
        if(ind==nums.size()-1)
        {
            if(a.size()>=2)
            {
                ans.insert(a);
            }
            return;
        }
           if(nums[ind+1]>=curr)
           {
               a.push_back(nums[ind+1]);
               solve(ind+1,ans,a,nums,nums[ind+1]);
               a.pop_back();
               
           }  
        solve(ind+1,ans,a,nums,curr);
     }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>a;
        for(int i=0;i<nums.size()-1;i++)
        {
        a.push_back(nums[i]);
        solve(i,ans,a,nums,nums[i]);
            a.pop_back();
        }
        vector<vector<int>>sol;
        for(auto x:ans)
        {
            sol.push_back(x);
        }
        
        return sol ;
    }
};