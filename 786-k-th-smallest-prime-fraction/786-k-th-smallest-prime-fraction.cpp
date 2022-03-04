class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,pair<int,int>>>vect;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                vect.push_back({double(arr[i])/arr[j],{arr[i],arr[j]}});
            }
        }
        priority_queue<pair<double,pair<int,int>>>p;
        for(auto x:vect)
        {
            if(p.size()<k)
                p.push({x.first,{x.second.first,x.second.second}});
            else
            {
                if(p.top().first>x.first)
                {p.pop();
                p.push({x.first,{x.second.first,x.second.second}});
                }
            }
        }
        vector<int>ans;
        ans.push_back(p.top().second.first);
        ans.push_back(p.top().second.second);
        return ans;
    }
};