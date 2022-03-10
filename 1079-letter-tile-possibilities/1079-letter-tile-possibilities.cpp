class Solution {
public:
    set<string>res;
    map<int,int>m;
    string s;
    void solve(string tiles)
    {
        for(int i=0;i<tiles.length();i++)
        {
            if(m[i]!=1)
            {
                s.push_back(tiles[i]);
                m[i]=1;
                res.insert(s);
                solve(tiles);
                m[i]=0;
                s.pop_back();
            }
        }
    }
    int numTilePossibilities(string tiles) {
        solve(tiles);
        return res.size();
    }
};