class Solution {
public:
    bool isvalid(char dig,int row,int col,vector<vector<char>>&board)
    {
        
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==dig)
                return false;
            if(board[i][col]==dig) 
                return false;
            if(board[(row/3)*3+i/3][(col/3)*3+i%3]==dig)
                return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>&board)
    {
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            if(board[i][j]=='.')
            {
                for(char k='1';k<='9';k++)
                {
                    if(isvalid(k,i,j,board))
                    {
                        board[i][j]=k;
                        if(solve(board)==true)
                            return true;
                        else
                        board[i][j]='.';    
                    }
                }
                return false;
            }   
        }
    }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};