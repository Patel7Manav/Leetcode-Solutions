class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size(); 
        if(n == 0) return 0;
      
        stack<int> st;
        st.push(-1);
        int maxarea=0;
     
        for(int i=0;i<n;i++){
         
            while(st.size()!=1 && heights[st.top()]>=heights[i]){
                int len = heights[st.top()];
                st.pop();
               
                int width = i-st.top()-1;
       
                maxarea=max(maxarea,len*width);
            }
           
            st.push(i);
        }
        
        while(st.size()!=1){
            int in=st.top();
            st.pop();
            int w = n-st.top() -1;
            int h = heights[in];
            maxarea = max(maxarea,w*h);
        }
        return maxarea; 
    }
};