class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>p;
        int i=0,n=matrix.size(),m=matrix[0].size(),c=0,row=0,col=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    p.push(matrix[i][j]);
                    c++;
                    if(c==k)
                    {   row=i;
                        col=j+1;
                        break;
                    }
                }
                if(c==k)
                    break;
            }
        if(col!=m)
        {
            for(col;col<m;col++)
            {
                int up=p.top();
                if(matrix[row][col]<up)
                {
                    p.pop();
                    p.push(matrix[row][col]);
                }
            }
        }
        for(int i=row+1;i<n;i++)
        {
            for(col=0;col<m;col++)
            {
                int up=p.top();
                if(matrix[i][col]<up)
                {
                    p.pop();
                    p.push(matrix[i][col]);
                }
            }
        }
        return p.top();
        
    }
};