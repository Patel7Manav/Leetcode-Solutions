class Solution {
public:
    bool halvesAreAlike(string s) {
       int t=s.length()/2;
        int c=0;
        for(int i=0;i<t;i++)
        {
           if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'  )
               c++;
        }
                for(int i=t;i<s.length();i++)
        {
           if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'  )
               c--;
        }
        if(c==0)
            return true;
        return false;
    }
};