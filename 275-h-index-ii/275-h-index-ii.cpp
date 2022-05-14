class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l=0,h=citations.size(),n=citations.size();
        if(citations[0]>n)
            return n;
        while(l<h)
        {
            int m=l+(h-l)/2;
            int x=citations[m];
            int cite=n-m;
            if(x==cite)
            {
                return x;
            }
            
            else if(x>cite)
                h=m;
            else
                l=m+1;
                
        }
        return n-l;
    }
};