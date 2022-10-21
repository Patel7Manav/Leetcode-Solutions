class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
       sort(arr.begin(), arr.end()); 
        int maxLength = 0, currentLength = 1,size=arr.size(); 
        if(size==0)
            return 0;
        for(int i = 1; i < size; i++) 
        {
            if(arr[i] == arr[i - 1] + 1) 
            {
                currentLength++; 
            }
            else if(arr[i] != arr[i - 1]) 
            {
                maxLength = max(maxLength, currentLength); 
                currentLength = 1; 
            }
        }
        
        maxLength = max(maxLength, currentLength); 
        return maxLength;
    }
};