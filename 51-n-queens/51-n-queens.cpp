class Solution {
public:
    void nqueen(int col,vector<vector<string>>&ans,vector<string>&a,vector<int>&row,vector<int>&ud,vector<int>&ld,int n)
    {
        if(col==n)
        {
            ans.push_back(a);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(row[i]==0 && ld[col+i]==0 && ud[n-1+(col-i)]==0)
            {
                row[i]=1;
                ld[col+i]=1;
                ud[n-1+(col-i)]=1;
                a[i][col]='Q';
                nqueen(col+1,ans,a,row,ud,ld,n);
                a[i][col]='.';
                 row[i]=0;
                ld[col+i]=0;
                ud[n-1+(col-i)]=0;
            }  
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>a(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            a[i]=s;
        vector<int>row(n,0);
        vector<int>ud(2*n-1,0);
        vector<int>ld(2*n-1,0);
        nqueen(0,ans,a,row,ud,ld,n);
        return ans;
    }
};