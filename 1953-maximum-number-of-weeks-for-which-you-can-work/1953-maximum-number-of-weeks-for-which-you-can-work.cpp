class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum=0;
        int n=milestones.size();
        sort(milestones.begin(),milestones.end());
        for(int i=0;i<n-1;i++)
            sum=sum+milestones[i];
        long long num=milestones[n-1];

        if(sum>=(num-1))
            return sum+num;
        else
            return sum*2+1;
        return 0;
    }
};