class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int st=0,end=n-1;
        int turn=0,alice=0,bob=0;
        while(st<end)
        {   int count=0;
            if(piles[st]>piles[end])
            { count=piles[st];
                st++;
            }
         else if(piles[st]<piles[end])
         {
             count=piles[end];
             end--;
         }
         else
         {
             if(st+1<end-1 && piles[st+1]>piles[end-1])
             {
                 count=piles[end];
                 end--;
             }
             else
             {
                 count=piles[st];
                 st++;
             }
         }
         if(turn==0)
             alice+=count;
         else
             bob+=count;
        }
        return alice>bob;
    }
};