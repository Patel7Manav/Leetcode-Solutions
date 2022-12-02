class Solution {
public:
    bool closeStrings(string word1, string word2) {
      if(word1.length()!=word2.length())
          return false;
        vector<int>cw1(26,0),cw2(26,0);
        for(auto x:word1)
            cw1[x-'a']++;
        for(auto x:word2)
            cw2[x-'a']++;
        for(int i=0;i<26;i++)
        {
            if((cw1[i]==0 && cw2[i]!=0) || (cw1[i]!=0 && cw2[i]==0))
                return false;
        }
        unordered_map<int,int>m;
        for(int i=0;i<26;i++)
        {
            if(cw1[i]!=0)
            m[cw1[i]]++;
            if(cw2[i]!=0)
            m[cw2[i]]--;
        }
        for(auto x:m)
            if(x.second!=0)
                return false;
        return true;
    }
    
};