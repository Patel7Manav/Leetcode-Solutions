class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>>p;
        for(auto it:m)
        {
            p.push({it.second,it.first});
        }
        vector<int>ans;
        int i=0;
        while(i<k)
        {   
          ans.push_back(p.top().second);
            p.pop();
            i++;
        }
        return ans;
    }
};