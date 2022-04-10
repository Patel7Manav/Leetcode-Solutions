class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>st;
        int ans=0;
        for(auto x:ops)
        {
            if(x=="+")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.push(a);
                st.push(a+b);
            }
            else if(x=="D")
            {
                st.push(st.top()*2);
            }
            else if(x=="C")
            {
                st.pop();
            }
            else
            {
                st.push(stoi(x));
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};