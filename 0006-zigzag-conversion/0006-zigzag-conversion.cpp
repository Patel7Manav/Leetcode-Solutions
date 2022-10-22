class Solution {
public:
    string convert(string s, int numRows) {
       vector<vector<char>>mat(numRows);
        int j;
        for(int i=0;i<s.length();i=j)
        {
            int k=0;
            for(j=i;j<s.length() && k<numRows;j++)
            {mat[k].push_back(s[j]);
            k++;
            }
            int a=numRows-2;
            for(a;a>0 && j<s.length();j++)
            {
                mat[a].push_back(s[j]);
                a--;
            }
        }
        string ans="";
        for(auto x:mat)
            for(auto y:x)
                ans.push_back(y);
        return ans;
    }
};