class Solution {
public:
    vector<int>serie;
    void fibon(int a,int b)
    {   int c=a+b;
        if(c>1000000000)
            return;
        serie.push_back(c);
        fibon(b,c);
    }
    int findMinFibonacciNumbers(int k) {
      serie.push_back(1);
    serie.push_back(1);
        fibon(1,1);
        int c=0;
        while(k)
        {
            c++;
            auto it=lower_bound(serie.begin(),serie.end(),k);
            int ind=it-serie.begin();
            if(serie[ind]==k)
                break;
            else
                k-=serie[ind-1];
        }
        return c;
    }
};