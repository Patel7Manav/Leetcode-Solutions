class Solution {
public:
    int longestConsecutive(vector<int>&arr) {
        if (arr.size() == 0)
    return 0;
int size=arr.size();
  sort(arr.begin(), arr.end());

  int longestCount = 0;
  int currCounter = 1;

  for (int i = 0; i < size - 1; i++) {
    if (arr[i + 1] - arr[i] == 1) {
      currCounter++;
    } else if (arr[i + 1] != arr[i]) {
      longestCount = max(longestCount, currCounter);
      currCounter = 1;
    }
  }
  longestCount = max(longestCount, currCounter);
  return longestCount;
    }
};