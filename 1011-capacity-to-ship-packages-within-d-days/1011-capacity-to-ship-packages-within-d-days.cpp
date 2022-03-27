class Solution {
public:
    bool isvalid(int mid,vector<int>a,int d)
    {   
        int n=a.size();
        for(int i=0;i<n;)
        {
            int j=i,sum=0;
            while(j!=n && (a[j]+sum)<=mid)
            {
                sum+=a[j];
                j++;
            }
            i=j;
            d--;
            if(d<0)
                return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size(),mx=0,sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=weights[i];
            mx=max(mx,weights[i]);
        }
        int lo=mx,hi=sum,ans=0;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            cout<<mid<<" ";
            if(isvalid(mid,weights,days))
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