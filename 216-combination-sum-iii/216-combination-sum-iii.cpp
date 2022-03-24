class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&a,int k,int n,int level)
    {
        
        if(k==0)
        {
            if(n==0)
            {
                ans.push_back(a);
            }
            return;
        }
        if(level>9)
            return;
        if(level<=n)
        {a.push_back(level);
        solve(ans,a,k-1,n-level,level+1);
         a.pop_back();
        }
        solve(ans,a,k,n,level+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>a;
        solve(ans,a,k,n,1);
        return ans;
    }
};