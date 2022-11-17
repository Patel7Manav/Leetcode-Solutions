class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int m=mat.size(),n=mat[0].size();
        int tot=m*n;
        vector<vector<int>>ans(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int row[]={0,-1,0,+1};
        int col[]={-1,0,+1,0};
        int curr=1;
        while(!q.empty())
        {
            int t=q.size();
            for(int i=0;i<t;i++)
            {
                pair<int,int>p=q.front();
                q.pop();
                int x=p.first,y=p.second;
                for(int a=0;a<4;a++)
                {
                        int tx=x+row[a];
                        int ty=y+col[a];
                        if(tx>=0 && tx<m && ty>=0 && ty<n && mat[tx][ty]==1)
                        {
                            mat[tx][ty]=0;
                            ans[tx][ty]=curr;
                            q.push({tx,ty});
                        }
                    
                }
            }
            curr++;
        }
        return ans;
    }
};