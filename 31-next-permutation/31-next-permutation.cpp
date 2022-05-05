class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),i,j,mx=INT_MAX,ind=n;
        if(n==1)
            return;
        bool flag=false;
        for( i=n-1;i>0;i--)
        {
                   if(nums[i]>nums[i-1])
                   {
                    flag=true;
                    break;}
        }

            if(flag==false)
                reverse(nums.begin(),nums.end());
        else{
       for(j=n-1;j>=i;j--)
       {
           if(nums[j]>nums[i-1])
           {
               if(nums[j]<mx)
               {    mx=nums[j];
                   ind=j;}
           }
       }
            swap(nums[i-1],nums[ind]);
            sort(nums.begin()+i,nums.end());
    }
    }
};