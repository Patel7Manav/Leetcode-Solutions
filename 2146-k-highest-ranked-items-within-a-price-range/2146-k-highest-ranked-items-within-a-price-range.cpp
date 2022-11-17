class Solution {
public:
    // static bool comp(const vector<int>&a, const vector<int>&b)
    // {
    //     if(a[2]<b[2])
    //         return true;
    //     else if(a[2]>b[2])
    //         return false;
    //     else 
    //     {
    //         if(a[3]<b[3])
    //             return true;
    //         else if(a[3]>b[3])
    //             return false;
    //         else
    //         {
    //             if(a[0]<b[0])
    //                 return true;
    //             else if(a[0]>b[0])
    //                 return false;
    //             else
    //             {
    //                 if(a[1]<b[1])
    //                     return true;
    //                 else
    //                     return false;
    //             }
    //         }
    //     }
    // }
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
       int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dis(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        q.push({start[0],start[1]});
        if(grid[start[0]][start[1]]>=pricing[0] && grid[start[0]][start[1]]<=pricing[1])
        {
            dis[start[0]][start[1]]=0;
        }
        int l=pricing[0],r=pricing[1];
        int curr=1;
        int dx[]={-1,0,+1,0};
        int dy[]={0,-1,0,+1};
        while(!q.empty())
        {
            int si=q.size();
            for(int j=0;j<si;j++)
            {
            pair<int,int>p=q.front();
            q.pop();
            int x=p.first,y=p.second;
            for(int i=0;i<4;i++)
            {
                int nx=dx[i]+x;
                int ny=y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && dis[nx][ny]==-1)
                {
                    if(grid[nx][ny]!=0)
                    q.push({nx,ny});
                    if(grid[nx][ny]>=l && grid[nx][ny]<=r)
                        dis[nx][ny]=curr;
                    else
                        dis[nx][ny]=-2;
                }
            }
            }
            curr++;
        }
        vector<vector<int>>arr;
        for(int i=0;i<m;i++)
        {   
            for(int j=0;j<n;j++)
            {       vector<int>temp;
                if(dis[i][j]>=0)
                {
                    
                    temp.push_back(dis[i][j]);
                    temp.push_back(grid[i][j]);
                    temp.push_back(i);
                      temp.push_back(j);
                    arr.push_back(temp);
                }
            }
        }
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(int i=0;i<k && i<arr.size();i++)
        {
            vector<int>temp;
            temp.push_back(arr[i][2]);
            temp.push_back(arr[i][3]);
            ans.push_back(temp);
        }
        return ans;
    }
};