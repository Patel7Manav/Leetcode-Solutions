class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
     int n=queries.size(),m=dictionary.size(),si=queries[0].length();
     vector<string>ans;
        for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             int c=0;
             for(int k=0;k<si;k++)
             {
                 if(queries[i][k]!=dictionary[j][k])
                     c++;
                 if(c>2)
                     break;
             }
             if(c<=2)
             {
                 ans.push_back(queries[i]);
                 break;
             }
         }
     }
        return ans;
    }
};