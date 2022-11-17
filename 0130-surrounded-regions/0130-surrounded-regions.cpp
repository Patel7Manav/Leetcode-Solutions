class Solution {
public:
    void bfs(int r,int c,vector<vector<char>>&board,vector<vector<char>>&ans,vector<vector<int>>&vis)
    {
        int m=board.size(),n=board[0].size();
        vis[r][c]=1;
        ans[r][c]='O';
        queue<pair<int,int>>q;
        q.push({r,c});
        int row[]={-1,0,+1,0};
        int col[]={0,-1,0,+1};
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            int x=p.first,y=p.second;
            for(int i=0;i<4;i++)
            {
                int tx=x+row[i];
                int ty=y+col[i];
                if(tx>0 && tx<m && ty>0 && ty<n && board[tx][ty]=='O' && vis[tx][ty]==0)
                {
                    vis[tx][ty]=1;
                    ans[tx][ty]='O';
                    q.push({tx,ty});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<char>>ans(m,vector<char>(n,'X'));
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O' && vis[0][i]==0)
            {
                bfs(0,i,board,ans,vis);
            }
            if(board[m-1][i]=='O' && vis[m-1][i]==0)
            {
                bfs(m-1,i,board,ans,vis);
            }
        }
        for(int i=1;i<m-1;i++)
        {
            if(board[i][0]=='O' && vis[i][0]==0)
            {
                bfs(i,0,board,ans,vis);
            }
            if(board[i][n-1]=='O' && vis[i][n-1]==0)
            {
                bfs(i,n-1,board,ans,vis);
            }
        }
        board=ans;
    }
};