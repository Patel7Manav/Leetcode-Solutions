class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=n-2;i>=0;i--)
        {   int j=i,t=0;
            vector<int>a;
            while(j<n)
            {
                a.push_back(matrix[j][t]);
                j++;
                t++;
            }
            j=i,t=0;
            int size=a.size()-1;
            while(j<n)
            {
                matrix[j][t]=a[size];
                t++;
                j++;
                size--;
            }
        }
        for(int i=1;i<n-1;i++)
        {   int j=i,t=0;
            vector<int>a;
            while(j<n)
            {
                a.push_back(matrix[t][j]);
                j++;
                t++;
            }
            j=i,t=0;
            int size=a.size()-1;
            while(j<n)
            {
                matrix[t][j]=a[size];
                t++;
                j++;
                size--;
            }
        }
        int i=0,j=n-1;
        while(i<j)
        {
            for(int k=0;k<n;k++)
            {
                swap(matrix[i][k],matrix[j][k]);
            }
            i++;
            j--;
        }
    }
};