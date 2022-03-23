class Solution {
public:
    void solve(int row,int col,vector<vector<char>>&board,string word,int ind,bool &flag,vector<vector<int>>&check)
    {   
         if(ind==word.length())
        {
            flag=true;
            return;
        }        

        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || check[row][col]==1)
            return;
       
                
                if(board[row][col]==word[ind])
                {
                    check[row][col]=1;
                    solve(row-1,col,board,word,ind+1,flag,check);
                    solve(row+1,col,board,word,ind+1,flag,check);
                    solve(row,col-1,board,word,ind+1,flag,check);
                    solve(row,col+1,board,word,ind+1,flag,check);
                    check[row][col]=0;
                }
                else {
                    return;
                }
            
    }
    bool exist(vector<vector<char>>& board, string word) {
      bool flag=false;
        vector<vector<int>>check;
        vector<int>a(board[0].size(),0);
        for(int i=0;i<board.size();i++)
        {
            check.push_back(a);
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++){
                 solve(i,j,board,word,0,flag,check);
            }
        }   
        return flag;
    }
};