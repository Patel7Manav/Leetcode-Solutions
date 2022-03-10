class CombinationIterator {
public:
    int cl;
    vector<string>cont;
    int in=0;
    void comb(string &s,string characters,int ind)
    {
        if(s.length()==cl)
        {
            cont.push_back(s);
            return;
        }
        if(ind>=characters.length())
            return;
        for(int i=ind;i<characters.length();i++)
        {
            s.push_back(characters[i]);
            comb(s,characters,i+1);
             s.pop_back();
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        cl=combinationLength;
        if(cl==1)
        {
             for(int i=0;i<characters.length();i++)
        {
           cont.push_back(string(1,characters[i]));
        }
        }
        else{
        for(int i=0;i<=characters.length()-cl;i++)
        {
            string s;
            s.push_back(characters[i]);
            comb(s,characters,i+1);
            s.pop_back();
        }}
        
    }
    string next() {
        return cont[in++];
    }
    
    bool hasNext() {
        if(in<cont.size())
            return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */