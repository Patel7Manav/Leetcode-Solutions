class FreqStack {
public:
    map<int,int>freq;
    map<int,vector<int>>mp;
    int mx=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        mx=max(mx,freq[val]);
        mp[freq[val]].push_back(val);    
    }
    
    int pop() {
        int n=mp[mx].size()-1;
        int val=mp[mx][n];
        mp[mx].pop_back();
        freq[val]--;
        if(mp[mx].empty())
            mx--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */