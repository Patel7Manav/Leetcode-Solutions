class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
      if(buckets==1)
          return 0;
        int div=minutesToTest/ minutesToDie;
        div++;
        buckets--;
        
        int req=log2(buckets)/log2(div);
        req++;
        return req;
    }
};