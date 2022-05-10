class Solution {
public:
    int solve(int n,int cop,int curr)
    {
        if(curr>n)
            return 1e8;
        if(curr==n)
            return 0;
        int left=1e8;
        if(cop!=0)
         left=1+solve(n,cop,curr+cop);  
        int right=2+solve(n,curr,curr+curr);
        return min(left,right);
    }
    int minSteps(int n) {
        if(n==1)
            return 0;
        if(n==2)
            return 2;
       return 1+solve(n,1,1);
    }
};