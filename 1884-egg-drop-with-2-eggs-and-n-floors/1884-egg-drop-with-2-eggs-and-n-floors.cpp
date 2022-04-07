class Solution {
public:
    int twoEggDrop(int n) {
        n=n*2;
        float x=sqrt(n);
        int g=floor(x);
        if(x-g>0.5)
        return x+1;
        else
            return x;
    }
};