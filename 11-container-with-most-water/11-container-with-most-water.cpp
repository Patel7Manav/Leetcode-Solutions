class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0,n=height.size();
        int l=0,h=n-1;
        while(l<h)
        {
            int area=min(height[l],height[h])*(h-l);
            ans=max(area,ans);
            if(height[l]<height[h])
                l++;
            else if(height[l]>height[h])
                h--;
            else
            {
                if(height[l+1]>height[h-1])
                    l++;
                else
                    h--;
            }
        }
        return ans;
    }
};