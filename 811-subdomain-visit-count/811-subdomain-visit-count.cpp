class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string,int>mp;
        int j,k;
        for(int i=0;i<cpdomains.size();i++)
        {
            string val="",a=cpdomains[i],dom="";
            for( j=0;;j++)
            {
                if(a[j]==' ')
                    break;
                val+=a[j];
            }
            int count=stoi(val);
            
            int c1=0,c2=0;
            for(k=j+1;k<a.size();k++)
            {
                dom+=a[k];
                if(a[k]=='.')
                {       if(c1==0)
                        c1=k-j;
                    else
                        c2=k-j;
                }
            }
            if(c2!=0)
            {
                string a=dom.substr(c1,dom.length()-c1);
                string b=dom.substr(c2,dom.length()-c2);
                mp[dom]+=count;
                mp[a]+=count;
                mp[b]+=count;
            }
            else
            {
                string a=dom.substr(c1,dom.length()-c1);
                 mp[dom]+=count;
                mp[a]+=count;
            }
        }
     vector<string>ans;
        for(auto x:mp)
        {
            string a="";
            a=a+to_string(x.second);
            a+=" ";
            a+=x.first;
            ans.push_back(a);
        }
        return ans;
    }
};