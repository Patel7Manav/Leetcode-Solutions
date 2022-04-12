class Solution {
public:
    int ischeck(int i,int j,vector<vector<int>>a,int n,int m)
    {
        int c=0;
        if(i-1>=0 && a[i-1][j]==1)
            c++;
        if(i-1>=0 && j-1>=0 && a[i-1][j-1]==1)
            c++;
        if(i-1>=0 && j+1<m && a[i-1][j+1]==1)
            c++;
        if(j-1>=0 && a[i][j-1]==1)
            c++;
        if(j+1<m && a[i][j+1]==1)
            c++;
        if(i+1<n && j-1>=0 && a[i+1][j-1]==1)
            c++;
        if(i+1<n && a[i+1][j]==1)
            c++;
        if(i+1<n && j+1<m && a[i+1][j+1]==1)
            c++;
        return c;
        
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>ans;
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {   vector<int>a;
            for(int j=0;j<m;j++)
            {
             if(board[i][j]==1)
             {
                if(ischeck(i,j,board,n,m)<2 || ischeck(i,j,board,n,m)>3)
                 a.push_back(0);
                 else
                     a.push_back(1);
             }
                else
                {
                    if(ischeck(i,j,board,n,m)==3)
                        a.push_back(1);
                    else
                        a.push_back(0);
                }
            }
         ans.push_back(a);
        }
         for(int i=0;i<n;i++)
        {   
            for(int j=0;j<m;j++)
            {
                board[i][j]=ans[i][j];
            }
        }
    }
};