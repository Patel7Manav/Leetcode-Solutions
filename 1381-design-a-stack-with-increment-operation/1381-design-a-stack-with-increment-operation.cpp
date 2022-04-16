class CustomStack {
public:
    int n,cap=0;
    stack<int>s;
    CustomStack(int maxSize) {
        n=maxSize;
    }
    
    void push(int x) {
        cap++;
        if(cap<=n)
        s.push(x);
        else
            cap=n;
    }
    
    int pop() {
        if(s.empty())
            return -1;
        int x=s.top();
        s.pop();
        cap--;
        return x;
    }
    
    void increment(int k, int val) {
        vector<int>arr;
        if(k<cap){
            int times=cap-k;
        while(times--)
        {
            arr.push_back(s.top());
            s.pop();
        }
        }
        while(!s.empty())
        {
            arr.push_back(val+s.top());
            s.pop();
        }
        reverse(arr.begin(),arr.end());
        for(auto x:arr)
        {s.push(x);
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */