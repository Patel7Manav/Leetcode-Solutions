class Solution {
public:
    int minimumSwap(string s1, string s2) {
       int cx=0,cy=0;
        for(auto x:s1)
        {
            if(x=='x')
                cx++;
        else
            cy++;
        }
        for(auto x:s2)
        {
            if(x=='x')
                cx++;
        else
            cy++;
        }
        if(cx%2!=0 || cy%2!=0)
            return -1;
        int c1=0,c2=0;
        for(int i=0;i<s1.length();i++)
        {if(s1[i]=='x' && s2[i]=='y')
                c1++;
        else if(s1[i]=='y' && s2[i]=='x')
            c2++;
        }
        return ceil(double(c1)/2)+ceil(double(c2)/2);
        return 0;
    }
};