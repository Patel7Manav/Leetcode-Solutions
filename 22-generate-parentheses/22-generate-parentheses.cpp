class Solution {
public:
    
    void fun(int i,int n,string curr,vector<string>&ans,int open,int close)
    {
        //base case
        if(i== 2*n)
        {
            ans.push_back(curr);
            return;
        }
        if(open<n)
        fun(i+1,n,curr+"(",ans,open+1,close);
        if(open>close)fun(i+1,n,curr+")",ans,open,close+1);
            
    }
    
    vector<string> generateParenthesis(int n) {
        string curr="" ;
        vector<string>ans;
        int open=0,close=0;
        fun(0,n,curr,ans,open,close);
        return ans;
    }
};