class Solution {
public:
    string getSmallestString(int n, int k) {
      string ans="";
        while(n)
       {
          if(n==1)
          {
              ans+=(k-1+'a');
              break;
          }
            if(ceil(floor(k-1)/(n-1))<=26)
           {
                ans+='a';
           }
            else
            {
                int ch=k-((n-1)*26);
                char letter=ch-1+'a';
                ans+=letter;
                ans+=string(n-1,'z');
                break;
            }
            n--;
            k--;
       }

        return ans;
    }
};