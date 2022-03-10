class Solution {
public:
    int issafe(vector<int>a,int h,int mi)
    {
        int c=0;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            c+=ceil(double(a[i])/mi);
            if(c>h)
                return 0;
        }
        return 1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        if(h==n)
            return piles[n-1];
        int lo=1,hi=piles[n-1];
        int ans=0;
        while(lo<=hi)
        {
            int mi=lo+(hi-lo)/2;
            if(issafe(piles,h,mi))
            {
                ans=mi;
                hi=mi-1;
            }
            else
                lo=mi+1;
        }
        return ans;
    }
};