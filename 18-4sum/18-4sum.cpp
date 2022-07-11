class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
     sort(nums.begin(),nums.end());
        set<vector<int>>res;
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int l=j+1,h=n-1;
                while(l<h)
                {
                    long int sum=long(nums[i])+long(nums[j])+long(nums[l])+long(nums[h]);
                    if(sum==target)
                    {
                        res.insert({nums[i],nums[j],nums[l],nums[h]});
                        l++;
                    }
                    else if(sum<target)
                        l++;
                    else
                        h--;
                }
            }
        }
        for(auto x:res)
            ans.push_back(x);
        return ans;
    }
};