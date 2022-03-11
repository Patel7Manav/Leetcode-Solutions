class Solution {
public:
    vector<string>ans;
    int len;
    void generate(string s,int l)
    {
        if(l+1==len)
        {ans.push_back(s);
        return;}
        if(s[l]=='a')
        {
            s.push_back('b');
            generate(s,l+1);
            s.pop_back();
            s.push_back('c');
            generate(s,l+1);
            s.pop_back();
        }
        else if(s[l]=='b')
        {
            s.push_back('a');
            generate(s,l+1);
            s.pop_back();
            s.push_back('c');
            generate(s,l+1);
            s.pop_back();
        }
        else
        {
            s.push_back('a');
            generate(s,l+1);
            s.pop_back();
            s.push_back('b');
            generate(s,l+1);
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) {   
        len=n;
        string s;
        s.push_back('a');
            generate(s,0);
        s.pop_back();
        s.push_back('b');
        generate(s,0);
        s.pop_back();
        s.push_back('c');
        generate(s,0);
        if(k>ans.size())
            return "";
        return ans[k-1];
        
    }
};