class Solution {
public:
    int shortestSubarray(vector<int>& arr, int k) {
       long long int n = arr.size();
  long long ans = INT_MAX;
        long long sum = 0;
  deque <pair<long long int,long long int>> q;
  for(long long int i = 0; i<n; i++){
      sum += arr[i];
      if(k <= sum)
      {
        ans = min(ans,i+1);
      }
      while(!q.empty() and sum-q.front().first>=k){
          ans = min(ans,i-q.front().second);
          q.pop_front();
      }
      while(!q.empty() && sum<q.back().first) 
      {
        q.pop_back();
      }
      q.push_back({sum,i});
  }
  if(ans == INT_MAX)
    return -1;
  
  return ans;
    }
};