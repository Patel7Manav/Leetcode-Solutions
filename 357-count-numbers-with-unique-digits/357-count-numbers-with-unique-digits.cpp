class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n==0)
            return 1;
        if(n==1)
            return 10;
        int dp[9];
        dp[0]=1;
        dp[1]=10;
        for(int i=2;i<=n;i++)
        {
            int j=i-1;
            int count=9,val=9;
            while(j--)
            {
                count=count*val;
                val--;
            }
            dp[i]=count+dp[i-1];
        }
        return dp[n];
    }
};