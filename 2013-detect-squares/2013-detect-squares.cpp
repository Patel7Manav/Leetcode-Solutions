class DetectSquares {
public:
    map<pair<int,int>,int>m;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        m[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int ans=0;
        for(auto i=m.begin();i!=m.end();i++)
        {
            if(i->first.first!=point[0] && abs(i->first.first-point[0])==abs(i->first.second-point[1]))
            {   
                if(m.find({i->first.first,point[1]})!=m.end() && m.find({point[0],i->first.second})!=m.end())
                {   
                    ans+=(m[{i->first.first,point[1]}]*m[{point[0],i->first.second}]*m[{i->first.first,i->first.second}]);
                }
                
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */