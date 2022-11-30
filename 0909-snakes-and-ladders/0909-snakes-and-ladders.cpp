class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
      int n=board.size();
        vector<int>arr;
        int j=0;
        for(int i=n-1;i>=0;i--)
        {
            if(j==0)
            {
                for(int k=0;k<n;k++)
                    arr.push_back(board[i][k]);
            }
            else
            {
                for(int k=n-1;k>=0;k--)
                    arr.push_back(board[i][k]);
            }
            j=j^1;
        }
        vector<int>vis(arr.size());
      queue<int>q;
        q.push(0);
        vis[0]=1;
        int ans=0;
        while(!q.empty())
        {
            int si=q.size();
            for(int i=0;i<si;i++)
            {
                int curr=q.front();
               
                if(curr==((n*n)-1))
                    return ans;
            
                q.pop();
                for(int nx=1;nx<=6;nx++)
                {
                    int temp=curr+nx;
                    if(temp>=(n*n))
                        continue;
                    if(arr[temp]==-1)
                    {   if(!vis[temp])
                    {
                        q.push(temp);
                    vis[temp]=1;
                    }
                    }
                    else
                    {   
                        if(!vis[arr[temp]-1])
                        { q.push(arr[temp]-1);
                        vis[arr[temp]-1]=1;
                    }
                    }
                }
            }
            ans++;
            
        }
        
        return -1;
    }
};