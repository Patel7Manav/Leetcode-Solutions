class Solution {
public:
     bool isvalid(char dig,int row,int col,vector<vector<char>>&board)
    {
        int c=0;
        for(int i=0;i<9;i++)
        {   
            if(board[row][i]==dig)
                c++;
            if(board[i][col]==dig) 
                c++;
            if(board[(row/3)*3+i/3][(col/3)*3+i%3]==dig)
                c++;
        }
         if(c>3)
        return false;
         else
         return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]!='.')
                {
                    if(isvalid(board[i][j],i,j,board)==false)
                        return false;
                }
            }
        }
        return true;
    }
};