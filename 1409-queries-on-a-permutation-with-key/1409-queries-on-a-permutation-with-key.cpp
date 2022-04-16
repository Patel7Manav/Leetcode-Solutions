class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int>perm;
        vector<int>ans;
        for(int i=1;i<=m;i++)
        {
            perm.push_back(i);
        }
        for(int i=0;i<queries.size();i++)
        {
            int num=queries[i];
            for(int j=0;j<perm.size();j++)
            {
                if(perm[j]==num)
                {   ans.push_back(j);
                    while(j>0)
                    {
                        perm[j]=perm[j-1];
                        j--;
                        
                    }
                    break;
                }
            }
            perm[0]=num;
        }
        return ans;
    }
};