class Solution {
public:
    int edgeScore(vector<int>& edges) {
      map<int,long long int>m;
        for(int i=0;i<edges.size();i++)
            m[edges[i]]+=i;
       long long int mx=INT_MIN,ind=-1;
        for(auto x:m)
        {
            if(x.second>mx)
            {
                mx=x.second;
                ind=x.first;
            }
        }
        return ind;
    }
};