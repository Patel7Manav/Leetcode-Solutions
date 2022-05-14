class Solution {
public:
    bool ischeck(int mid,vector<int>&dist,double hour)
    {
        double time=0;
        int n=dist.size();
        for(int i=0;i<dist.size()-1;i++)
        {
            time+=double(ceil(double(dist[i])/mid));
        }
       
        time+=double(double(dist[n-1])/mid);
        if(time<=hour)
            return true;
        return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size(),mx=0;
        if(float(n-1)>hour)
            return -1;
        int l=1,h=1e7,ans=-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(ischeck(mid,dist,hour))
            {
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};