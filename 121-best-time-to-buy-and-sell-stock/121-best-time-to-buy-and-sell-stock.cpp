class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mn=prices[0],prof=INT_MIN;
        for(int i=1;i<n;i++)
        {
            prof=max(prof,prices[i]-mn);
            mn=min(mn,prices[i]);
        }
        if(prof<=0)
            return 0;
        return prof;
    }
};