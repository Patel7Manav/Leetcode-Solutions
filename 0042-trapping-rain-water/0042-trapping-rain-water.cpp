class Solution {
public:
    int trap(vector<int>& height) {
       int n=height.size();
        vector<int>left(n,0),right(n,0);
        int mx=0;
        for(int i=1;i<n-1;i++)
        {
           left[i]=max(height[i-1],mx);
            mx=max(mx,left[i]);
        }
         mx=0;
        for(int i=n-2;i>0;i--)
        {
            right[i]=max(height[i+1],mx);
            mx=max(mx,right[i]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            int temp=min(right[i],left[i]);
            if((temp-height[i])>0)
                ans+=(temp-height[i]);
        }
        return ans;
    }
};