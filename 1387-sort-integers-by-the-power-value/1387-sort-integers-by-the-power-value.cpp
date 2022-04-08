class Solution {
public:
    int solve(int n)
    {
        if(n==1)
            return 0;
        if(n%2==0)
            return 1+solve(n/2);
        else
            return 1+solve((3*n)+1);
    }
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int,int>>p;
        int i=0;
        while(i<k)
        {
            int count=solve(lo);
            p.push(make_pair(count,lo));
            lo++;
            i++;
        }
        while(lo<=hi)
        {
            int count=solve(lo);
            
            if(count<p.top().first)
            {
                p.pop();
                p.push(make_pair(count,lo));
                
            }
            lo++;
        }
        return p.top().second;
    }
};