class Solution {
public:
    bool canMeasureWater(int j1C, int j2C, int tC) {
       if((j1C+j2C)<tC)
           return false;
        if((j1C+j2C)==tC)
            return true;
        int mx=max(j1C,j2C);
        int mn=min(j1C,j2C);
        if(tC==mx || tC==mn || tC==(mx-mn))
            return true;
        if(__gcd(mx,mn)!=1)
        {
            if(__gcd(tC,mn)!=1)
                return true;
            return false;
        }
        else
        {
            return true;
        }
       return true; 
    }
};