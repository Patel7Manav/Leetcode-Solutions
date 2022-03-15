class Solution {
public:
   void comb(int ind,vector<int>&a,vector<vector<int>>&ans,vector<int>cand,int target)
    {
       if(target==0)
       {
           ans.push_back(a);
           return;
       }
       for(int i=ind;i<cand.size();i++)
       {
           if(i>ind && cand[i]==cand[i-1])
               continue;
           if(cand[i]>target)
               break;
           a.push_back(cand[i]);
           comb(i+1,a,ans,cand,target-cand[i]);
           a.pop_back();
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>a;
        sort(candidates.begin(),candidates.end());
        comb(0,a,ans,candidates,target);
        return ans;
    }
};