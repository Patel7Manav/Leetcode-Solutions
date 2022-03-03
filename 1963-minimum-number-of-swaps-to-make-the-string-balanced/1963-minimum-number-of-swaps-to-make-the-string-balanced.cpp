class Solution {
public:
    int minSwaps(string s) {
        int extra=0,mxextra=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='[')
            extra--;
            else
                extra++;
            mxextra=max(mxextra,extra);
        }
        return (mxextra +1)/2; 
    }
};