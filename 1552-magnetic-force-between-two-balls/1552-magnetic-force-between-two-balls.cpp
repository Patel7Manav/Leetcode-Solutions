class Solution {
public:
    bool isvalid(int mid,vector<int>position,int m,int n)
    {
        int count=1,curr=position[0];
        for(int i=1;i<n;i++)
        {
            if(position[i]-curr>=mid)
            {
                count++;
                curr=position[i];
            }
        }
        if(count>=m)
            return true;
        return false;
        
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size(),mx=0,mn=INT_MAX,curr=0;
        sort(position.begin(),position.end());
        for(int i=0;i<n;i++)
        {
            mx=max(mx,position[i]);
            mn=min(mn,position[i]);
        }
        int hi=mx-mn,ans=0,lo=0;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(isvalid(mid,position,m,n))
            {
                ans=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        return ans;
    }
};