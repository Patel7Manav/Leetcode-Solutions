class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>p;
        for(auto x:stones)
            p.push(x);
        while(true)
        {
            if(p.size()==1)
                return p.top();
            else if(p.size()==0)
                return 0;
            else
            {
                int x=p.top();
                p.pop();
                int y=p.top();
                p.pop();
                if(x!=y)
                p.push(x-y);
            }
        }
        return 0;
    }
};