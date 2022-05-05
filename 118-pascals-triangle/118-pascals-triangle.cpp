class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1)
            return {{1}};
        vector<vector<int>>ans;
        ans.push_back({1});
        ans.push_back({1,1});
        for(int i=2;i<numRows;i++)
        {
         vector<int>a;
            a.push_back(1);
            for(int j=0;j<ans[i-1].size()-1;j++)
            {
                a.push_back(ans[i-1][j]+ans[i-1][j+1]);
            }
            a.push_back(1);
            ans.push_back(a);
        }
        return ans;
    }
};