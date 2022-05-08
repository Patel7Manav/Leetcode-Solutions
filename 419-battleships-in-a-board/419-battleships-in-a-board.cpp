class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count=0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='X')
                {
                    if((i+1==board.size() || board[i+1][j]!='X') && (i-1==-1 || board[i-1][j]!='X'))
                    {count++;
                        int k=j;
                        while(k<board[0].size() && board[i][k]=='X')
                        {
                         board[i][k]='.';
                            k++;
                        }
                    }
                }
            }
        }
        for(int i=0;i<board[0].size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                if(board[j][i]=='X')
                {
                    if((i+1==board[0].size() || board[j][i+1]!='X') && (i-1==-1 || board[j][i-1]!='X'))
                    {count++;
                        int k=j;
                        while(k<board.size() && board[k][i]=='X')
                        {
                         board[k][i]='.';
                            k++;
                        }
                    }
                }
            }
        }
        return count;
    }
};