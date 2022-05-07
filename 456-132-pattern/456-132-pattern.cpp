class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>>st;
        int currmin=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() && nums[i]>st.top().first)
                st.pop();
            if(!st.empty() &&nums[i]<st.top().first && nums[i]>st.top().second)
                return true;
            currmin=min(currmin,nums[i]);
            st.push({nums[i],currmin});
        }
        return false;
    }
};