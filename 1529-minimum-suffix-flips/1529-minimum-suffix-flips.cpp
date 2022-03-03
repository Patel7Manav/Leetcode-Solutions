class Solution {
public:
    int minFlips(string target) {
        string ans="";
        int l=target.length();
        ans+=string(l,'0');
        int c=0;
        for(int i=0;i<l;i++)
        {
           if(target[i]!=ans[i])
           {
               c++;
               int occ=l-i;
               char ch;
               if(ans[i]=='1')
                   ch='0';
               else
                   ch='1';
               ans.replace(i,occ,occ,ch);
           }
        }
        return c;
    }
};