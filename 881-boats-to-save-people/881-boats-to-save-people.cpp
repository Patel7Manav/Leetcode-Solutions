class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.rbegin(),people.rend());
       int i=0,j=people.size()-1;
        int c=0;
        while(i<j)
        {   
            c++;
            if(people[i]+people[j]<=limit)
                j--;
            i++;
        }
        if(i==j)
            c++;
        return c;
        }
    
};