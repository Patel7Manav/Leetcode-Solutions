class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner,count=0;
        winner=arr[0];
        if(k>=arr.size())
            return *max_element(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>winner)
            {
                winner=arr[i];
                count=1;
            }
            else
                count++;
            if(count==k)
                return winner;
        }
        return winner;
    }
};