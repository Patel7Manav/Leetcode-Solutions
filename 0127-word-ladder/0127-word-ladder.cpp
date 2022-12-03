class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        int le=beginWord.length();
        bool flag=false;
         queue<int>q;
        vector<int>vis(n,0);
         for(int i=0;i<n;i++)
         {
             if(wordList[i]==endWord)
                 flag=true;
             int c=0;
             for(int j=0;j<le;j++)
             {
                 if(wordList[i][j]!=beginWord[j])
                     c++;
                 if(c>1)
                     break;
             }
             if(c==1)
             {
                 q.push(i);
                 vis[i]=1;
             }
         }
        if(flag==false)
            return 0;
        int ans=0;
        while(!q.empty())
        {   ans++;
            int si=q.size();
         for(int k=0;k<si;k++)
         {
            int t=q.front();
            q.pop();
            if(wordList[t]==endWord)
            { 
                return ans+1;
            }
            for(int i=0;i<n;i++)
        {
            if(vis[i])
                continue;
                int c=0;
            for(int j=0;j<le;j++)
             {
                 if(wordList[i][j]!=wordList[t][j])
                     c++;
                 if(c>1)
                     break;
             }
             if(c==1)
             {
                 q.push(i);
                 vis[i]=1;
             }
        }    
         }
        }
       return 0; 
    }
};