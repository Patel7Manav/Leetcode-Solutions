class Solution {
public:
    struct comp{
        
        bool operator()(pair<int, int>& a, pair<int, int>& b)
        {
            if(a.first!=b.first)
                return a.first<b.first;
            else
            return a.second<b.second;        
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>p;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<k;i++)
        {   int c=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                    c++;
            }
            cout<<c<<" ";
            p.push(make_pair(c,i));
        }
        for(int i=k;i<n;i++)
        {   int c=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                    c++;
            }
            int mx=p.top().first;
         int my=p.top().second;
         cout<<mx<<" "<<my<<" ";
         cout<<c<<" ";
            if(c<mx)
            {
                p.pop();
                p.push(make_pair(c,i));
            }
        }
        vector<int>ans;
        while(!p.empty())
        {
            ans.push_back(p.top().second);
            p.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};