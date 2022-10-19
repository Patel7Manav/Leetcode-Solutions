class Solution {
public:
    int calPoints(vector<string>& ops) {
        int value1 = 0;
      int value2 = 0;
      int doubleData = 0;
      int ans = 0;
      stack<int> _stack;
      for(int i = 0; i < ops.size(); i++)
      {
        if(ops[i] == "C")
        {
          _stack.pop();
        }
        else if(ops[i] == "D")
        {
          doubleData = _stack.top() * 2;
          _stack.push(doubleData);
        }
        else if(ops[i] == "+")
        {
          value1 = _stack.top();
          _stack.pop();
          value2 = _stack.top();
          _stack.push(value1);
          _stack.push(value1 + value2);
        }
        else
        {
          _stack.push(stoi(ops[i]));
        }
      }
      while(_stack.size() != 0)
        {
          ans += _stack.top();
          _stack.pop();
        }
        return ans;
    } 
    
};