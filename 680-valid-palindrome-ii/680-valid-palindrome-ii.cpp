class Solution {
public:
    bool validPalindrome(string s) {
        int l=0,h=s.length()-1;
        while(l<=h)
        {
            if(s[l]!=s[h])
            {
               int l1=l+1,h1=h;
                int l2=l,h2=h-1;
               while(l1<h1 && s[l1]==s[h1])
               {
                   l1++;
                   h1--;
               }
                while(l2<h2 && s[l2]==s[h2])
                {
                    l2++;
                    h2--;
                }
                if(l1<h1 && l2<h2)
                    return false;
                else return true;
            }
            else
            {  
                l++;
                h--;
            }
        }
        return true;
    }
};