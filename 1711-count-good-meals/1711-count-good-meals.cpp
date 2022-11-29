class Solution {
public:
    int countPairs(vector<int>& del) {
     unordered_map<int,int>m;
        vector<int>pow2;
        for(int i=0;i<=21;i++)
            pow2.push_back(pow(2,i));
       long int ans=0;
        for(int x:del)
        {   
            for(int i=0;i<23;i++)
            {
                int diff=pow2[i]-x;
                if(m.find(diff)!=m.end())
                {
                   ans=ans+(m[diff])%1000000007;
                }
               
            }
             m[x]++;
        }
        return ans%int(1000000007);
    }
};