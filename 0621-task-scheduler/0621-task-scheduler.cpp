class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       if(n==0)
           return tasks.size();
        vector<int>count(26,0);
        for(auto x:tasks)
        {
            count[x-'A']++;
           
        }
       
        int mx=*max_element(count.begin(),count.end());
       
        int c=0;
        for(auto a:count)
        {
            if(a==mx)
                c++;
        }
        int ans=1+(n+1)*(mx-1);
        if(c!=1)
        {
            ans+=(c-1);
        }
        int num=tasks.size();
        return max(num,ans);
    }
};