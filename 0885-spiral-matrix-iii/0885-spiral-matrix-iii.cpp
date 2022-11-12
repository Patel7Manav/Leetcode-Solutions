class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int tot=rows*cols;
        vector<vector<int>>ans;
        ans.push_back({rStart,cStart});
        int count=1,st=0;
        int x=rStart,y=cStart;
        while(count<tot)
        {
            st++;
            for(int i=1;i<=st;i++)
            {
                y++;
                if(x<rows && x>=0 && y<cols && y>=0)
                {ans.push_back({x,y});
                count++;
                }
            }
            for(int i=1;i<=st;i++)
            {
                x++;
                if(x<rows && x>=0 && y<cols && y>=0)
                {ans.push_back({x,y});
                count++;
                }
            }
            st++;
            for(int i=1;i<=st;i++)
            {
                y--;
                if(x<rows && x>=0 && y<cols && y>=0)
                {ans.push_back({x,y});
                count++;
                }
            }
            for(int i=1;i<=st;i++)
            {
                x--;
                if(x<rows && x>=0 && y<cols && y>=0)
                {ans.push_back({x,y});
                count++;
                }
            }
        }
        return ans;
    }
};