class Solution {
public:
    set<vector<int>>ans;
    void generate(vector<int>nums,vector<int>a,int ind)
    {
        if(ind==nums.size())
        {
            ans.insert(a);
            return;
        }
        for(int i=ind;i<nums.size();i++)
        {
            generate(nums,a,i+1);
            a.push_back(nums[i]);
            generate(nums,a,i+1);
            a.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int>a;
        for(int i=0;i<nums.size();i++)
        {   a.push_back(nums[i]);
            generate(nums,a,i+1);
         a.pop_back();
        }
        vector<vector<int>>res;
        for(auto x:ans)
        { 
         res.push_back(x);
        }
        res.push_back({});
        return res;
    }
};