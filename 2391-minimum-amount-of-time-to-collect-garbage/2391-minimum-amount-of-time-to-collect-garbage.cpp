class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        for(int i=1;i<travel.size();i++)
            travel[i]+=(travel[i-1]);
        int p=-1,g=-1,m=-1,ans=0;
        for(int i=0;i<garbage.size();i++)
        {
            int pl=count(garbage[i].begin(),garbage[i].end(),'P'),gl=count(garbage[i].begin(),garbage[i].end(),'G'),ml=count(garbage[i].begin(),garbage[i].end(),'M');
            ans+=(pl);
            ans+=(gl);
            ans+=(ml);
            if(pl!=0)
                p=i-1;
            if(gl!=0)
                g=i-1;
            if(ml!=0)
                m=i-1;
            cout<<ans<<" ";
        }
        if(m!=-1)
            ans+=travel[m];
        if(g!=-1)
            ans+=travel[g];
        if(p!=-1)
            ans+=travel[p];
        return ans;
    }
};