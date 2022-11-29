class Solution {
public:
    int countPairs(vector<int>& del) {
     unordered_map<int,pair<bool,int>>m;
        for(auto x:del)
            m[x].second++;
        vector<int>pow2;
        for(int i=0;i<=21;i++)
            pow2.push_back(pow(2,i));
      long int ans=0;
        for(auto x:m)
        {   long int a=x.first,b=x.second.second; 
            for(int i=0;i<23;i++)
            {
                long int diff=pow2[i]-a;
                if(m.find(diff)!=m.end() && m[diff].first==false)
                {
                    
                    if(diff==a)
                    {
                        ans=ans+((b*(b-1))/2)%1000000007;
                    }
                    else
                    {
                        ans=ans+(m[diff].second*b)%1000000007;
                    }
                }
            }
         m[a].first=true;
        }
        return ans%int(1000000007);
    }
};