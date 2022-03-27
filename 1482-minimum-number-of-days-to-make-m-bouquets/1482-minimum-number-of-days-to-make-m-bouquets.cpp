class Solution {
public:
    bool isvalid(int mid,vector<int>a,int m,int k)
    {
        int c=0,n=a.size();
        for(int i=0;i<n;)
        {
            if(mid>=a[i])
            {
                int curr=1;
                int j=i+1;
                while(j!=n && mid>=a[j] && curr<k)
                {
                    j++;
                    curr++;
                }
                i=j;
                if(curr==k)
                    c++;
            }
            else
                i++;
        }
        if(c>=m)
            return true;
        return false;
        
        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((m*k)>n)
            return -1;
        int lo=INT_MAX,hi=0;
        for(int i=0;i<n;i++)
        {
            lo=min(lo,bloomDay[i]);
            hi=max(hi,bloomDay[i]);
        }
        int ans=0;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(isvalid(mid,bloomDay,m,k))
            {
                ans=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        return ans;
    }
};