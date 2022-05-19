class Solution {
public:
   string find(string &pick, string &nopick)
   {
       if(pick.find('0')!=string::npos) return nopick;
       if(nopick.find('0')!=string::npos) return pick;
       if(pick.length()>nopick.length())
           return pick;
       else if(pick.length()<nopick.length())
           return nopick;
       else
       {
           if(pick>nopick)
               return pick;
           else
               return nopick;
       }
   }
   string solve(vector<int>&cost,int ind,int target,vector<vector<string>>&dp)
    {
        if(target==0)
            return "";
       if(target<0 || ind==10)
           return "0";
        
       if(dp[ind][target]!="-1")
           return dp[ind][target];
       
       string pick=to_string(ind)+solve(cost,1,target-cost[ind-1],dp);
       string nopick=solve(cost,ind+1,target,dp);
        return dp[ind][target]=find(pick,nopick);
    }
    string largestNumber(vector<int>& cost, int target) {
        
        vector<vector<string>>dp(cost.size()+1,vector<string>(target+1,"-1"));
      string ans= solve(cost,1,target,dp);
       if(ans=="")
           return "0";
        return ans;
    }
};