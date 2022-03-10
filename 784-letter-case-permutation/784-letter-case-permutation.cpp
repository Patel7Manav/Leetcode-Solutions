class Solution {
public:
    vector<string>ans;
    void find(string s,string curr,int ind){
        if(ind>=s.length())
        {
            ans.push_back(curr);
            return;
        }
        if(s[ind]>=48 && s[ind]<=57)
        {
            find(s,curr+s[ind],ind+1);
        }
        else
        {
            find(s,curr+char(tolower(s[ind])),ind+1);
            find(s,curr+char(toupper(s[ind])),ind+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        string curr="";
        find(s,curr,0);
        return ans;
    }
};