class Solution {
public:
    void solve(vector<int>&nums,vector<int>&res,int target,int lo,int hi)
    {   
        if(lo>hi)
        return;
        
     int l=lo,h=hi;
       while(l<=h)
        {
            int m=l+(h-l)/2;
            if(nums[m]==target)
            {
                if(res.empty())
                {
                    res.push_back(m);
                    res.push_back(m);
                    
                }
                else 
                {
                    if(res[0]>m)
                        res[0]=m;
                    else if(m>res[1])
                        res[1]=m;
                }
                if(m-1>=0 && nums[m-1]==target)
                solve(nums,res,target,lo,m-1);
                if(m+1<nums.size()&& nums[m+1]==target)
                solve(nums,res,target,m+1,hi);
                break;
            }
            else if(nums[m]<target)
                l=m+1;
           else
               h=m-1;
        }
        return;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int>res;
        int l=0,h=nums.size()-1;
        solve(nums,res,target,l,h);
        if(res.empty())
        {
            res.push_back(-1);
            res.push_back(-1);
        }
        return res;
    }
};