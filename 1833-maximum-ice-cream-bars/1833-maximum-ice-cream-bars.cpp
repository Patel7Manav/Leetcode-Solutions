class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n=costs.size(),res=0;
        for(int i=0;i<n;i++)
        {
            if(costs[i]>coins)
                break;
            res++;
            coins-=costs[i];
        }
        return res;
    }
};