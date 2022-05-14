class Solution {
public:
    bool ischeck(vector<int>&arr,int m)
    {   int n=arr.size(),c=0,j=-1;
        for(int i=n-1;i>=0;i--)
        {   if(c==m)
        {
            j=i;
            break;
        }
            if(arr[i]>=m)
            {
                c++;
            }
         else
             break;
        }
     
     if(c<m)
         return false;
     for(int i=0;i<=j;i++)
     {
         if(arr[i]>m)
             return false;
     }
     return true;
    }
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n=citations.size();
        int l=1,h=citations[n-1],ans=0;
        while(l<=h)
        {
         
            if(ischeck(citations,l))
            {
                ans=l;
            
            }
            
                l++;
        }
        return ans;
    }
};