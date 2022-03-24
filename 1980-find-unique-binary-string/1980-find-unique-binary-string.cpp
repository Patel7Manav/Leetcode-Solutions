class Solution {
public:
    bool find(string curr,vector<string>nums)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==curr)
                return true;
        }
        return false;
    }
    void solve(string& ans,vector<string> nums,int n,string curr,bool& flag)
    {
        if(curr.length()==n)
        {
            if(find(curr,nums)==false)
            {
                ans+=curr;
                flag=true;
            }
            return;
        }
        solve(ans,nums,n,curr+"0",flag);
        if(flag==true)
            return;
        solve(ans,nums,n,curr+"1",flag);
        if(flag==true)
            return;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string ans="";
        int n=nums.size();
        string curr="";
        bool flag=false;
        solve(ans,nums,n,curr,flag);
        return ans;
    }
};