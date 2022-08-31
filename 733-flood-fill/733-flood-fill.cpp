class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      int m=image.size(),n=image[0].size();
       vector<vector<int>>vis(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        int temp=image[sr][sc];
       q.push({sr,sc});
        while(!q.empty())
        {
            pair<int,int>curr=q.front();
            int r=curr.first,c=curr.second;
            q.pop();
            image[r][c]=color;
            vis[r][c]=0;
            if(r-1>=0 && image[r-1][c]==temp && vis[r-1][c]==-1)
                q.push({r-1,c});
            if(r+1<m && image[r+1][c]==temp && vis[r+1][c]==-1)
                q.push({r+1,c});
            if(c-1>=0 && image[r][c-1]==temp && vis[r][c-1]==-1)
                q.push({r,c-1});
            if(c+1<n && image[r][c+1]==temp && vis[r][c+1]==-1)
                q.push({r,c+1});        
        }
        return image;
    }
};