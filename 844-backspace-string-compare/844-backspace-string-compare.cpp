class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string t1="",t2="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='#')
            {
                if(!t1.empty())
                    t1.pop_back();
            }
            else
                t1.push_back(s[i]);
        }
        for(int i=0;i<t.length();i++)
        {
            
            if(t[i]=='#')
             {
                if(!t2.empty())
                    t2.pop_back();
            }
            else
                t2.push_back(t[i]);   
        }
        if(t1==t2)
        return true;
        return false;
    }
};