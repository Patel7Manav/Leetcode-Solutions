class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
       int n=nums1.size(),mx=INT_MIN,sum1=0,sum2=0;
        int curr=0;
        for(int i=0;i<n;i++)
        {
             curr+=nums2[i]-nums1[i];
            mx=max(curr,mx);
            if(curr<0)
                curr=0;
            sum1+=nums1[i];
        }
        int res1=sum1+mx;
        mx=INT_MIN;
        curr=0;
        for(int i=0;i<n;i++)
        {
            curr+=nums1[i]-nums2[i];
            mx=max(curr,mx);
            if(curr<0)
                curr=0;
            sum2+=nums2[i];
        }
        int res2=sum2+mx;
        return max(res1,res2);
    }
};