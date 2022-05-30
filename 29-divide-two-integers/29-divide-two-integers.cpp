class Solution {
public:
    int divide(int dividend, int divisor) {
          long long quot=  (long long)dividend/divisor;
        if(quot>2147483647)
            return 2147483647;
        if(quot<-2147483648)
            return -2147483648;
        return quot;
    }
};