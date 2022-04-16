class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
       int m=mat.size(),n=mat[0].size();
        if(m==1 || n==1)
            return mat;
        for(int i=m-1;i>=0;i--)
        {
            vector<int>a;
            int k=0;
            for(int j=i;j<m && k<n;j++)
            {
                a.push_back(mat[j][k]);
                k=k+1;
            }
            sort(a.begin(),a.end());
             k=0;
            int t=0;
            for(int j=i;j<m && k<n;j++)
            {
                mat[j][k]=a[t];
                k=k+1;
                t++;
            }
        }
        for(int i=1;i<n;i++)
        {
            vector<int>a;
            int k=0;
            for(int j=i;j<n && k<m;j++)
            {
                a.push_back(mat[k][j]);
                k=k+1;
            }
            sort(a.begin(),a.end());
             k=0;
            int t=0;
            for(int j=i;j<n && k<m;j++)
            {
                mat[k][j]=a[t];
                k=k+1;
                t++;
            }
        }
        return mat;
    }
};