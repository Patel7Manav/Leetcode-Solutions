class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,k=0,l=m;
        while(j<m && k<n)
        {
            if(nums1[i]<=nums2[k])
            {
                j++;
                i++;
            }
            else
            {int temp=l;
             while(temp>i && temp>0)
             {
                 nums1[temp]=nums1[temp-1];
                 temp--;
             }
             nums1[i]=nums2[k];
             i++;
             k++;
             l++;
            }
        }
        if(k<n)
        {
            while(k<n)
            {nums1[i]=nums2[k];
            k++;
            i++;}
        }
    }
};