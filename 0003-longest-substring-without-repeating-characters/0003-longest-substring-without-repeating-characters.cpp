class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int n = s.length();
    int maxLen = 0;

    int i = 0;
    while (i < n)
    {
        int charArray[256] = {0};
        int j = i;
        int currLen = 0;

        for (int j = i; j < n; j++)
        {
            if (++charArray[s[j]] <= 1)
            {
                currLen++;
                maxLen = maxLen < currLen ? currLen : maxLen;
            }
            else
            {
                charArray[s[j]] = 0;
                break;
            }
        }
        i++;
    }
    return maxLen;
    }
};