class Solution {
public:
    int trap(vector<int>& nums) {
       int n=nums.size();
        int first = 0, last = n - 1;
    int f_max = 0, l_max = 0;
    int ans = 0;
    while (first <= last) {
      if (l_max <= f_max) {
        ans += max(0, l_max - nums[last]);
        l_max = max(l_max, nums[last]);
        last -= 1;
      } else {
        ans += max(0, f_max - nums[first]);
        f_max = max(f_max, nums[first]);
        first += 1;
      }
    }
    return ans;
    }
};