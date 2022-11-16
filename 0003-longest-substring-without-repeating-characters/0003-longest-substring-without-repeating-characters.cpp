class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> res;

    int right = 0;
    int left = 0;

    int ans = 0;

    while(right < s.length()) {
      char r = s[right];
      res[r]++;

      while(res[r] > 1) {
        char l = s[left];
        res[l]--;
        left++;
      }

      ans = max(ans, right - left + 1);

      right++;
    }

    return ans;
    }
};