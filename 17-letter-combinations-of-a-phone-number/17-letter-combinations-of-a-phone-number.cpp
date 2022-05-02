class Solution {
public:
    void solve(string digits,int ind,string &curr,vector<string> &ans,map<int,vector<char>>&m)
    {   
        if(ind>=digits.size())
        {
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<m[digits[ind]-'0'].size();i++)
        {
            curr=curr+m[digits[ind]-'0'][i];
            solve(digits,ind+1,curr,ans,m);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return {};
        map<int,vector<char>>m;
        m[2]={'a','b','c'};
        m[3]={'d','e','f'};
        m[4]={'g','h','i'};
        m[5]={'j','k','l'};
        m[6]={'m','n','o'};
        m[7]={'p','q','r','s'};
        m[8]={'t','u','v'};
        m[9]={'w','x','y','z'};
        vector<string>ans;
        string curr="";
         solve(digits,0,curr,ans,m);
        return ans;
    }
};