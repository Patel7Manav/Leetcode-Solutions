class Solution {
public:
int solve(vector<vector<int>>&wor,vector<int>&count,vector<int>&score,int i)
{
    if(i==wor.size())
        return 0;
    bool flag=true;
    for(int j=0;j<26;j++)
    {
        if(wor[i][j]>count[j])
        {flag=false;
        break;}
    }
    int pick=INT_MIN,sc=0;
    if(flag==true)
    {   vector<int>cou;
     cou=count;
        for(int j=0;j<26;j++)
        {
           count[j]-=wor[i][j];
           sc+=(wor[i][j]*score[j]);
        }
        pick=sc+solve(wor,count,score,i+1);
     count=cou;
    }
    int nopick=solve(wor,count,score,i+1);
    return max(pick,nopick);
}
int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
      int m=words.size();
        vector<vector<int>>wor(m,vector<int>(26,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                wor[i][words[i][j]-'a']++;
            }
        }
        vector<int>count(26,0);
        for(int i=0;i<letters.size();i++)
            count[letters[i]-'a']++;
        return solve(wor,count,score,0);
    }
};