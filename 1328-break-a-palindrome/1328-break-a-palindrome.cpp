class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len=palindrome.length();
        if(len==1)
            return "";
        int n=len/2;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if(palindrome[i]=='a')
                continue;
            else
            {palindrome[i]='a';
            flag=true;
             break;}
        }
        if(flag==false)
        {
            palindrome[len-1]='b';
        }
        return palindrome;
    }
};