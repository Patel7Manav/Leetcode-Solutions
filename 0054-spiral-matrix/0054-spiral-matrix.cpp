class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int top=0,left=0,right=matrix[0].size()-1,bottom=matrix.size()-1;
        vector<int>ans;
        while(top<=bottom && left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            if(top>bottom)
                break;
            for(int i=top;i<=bottom;i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(right<left)
                break;
            for(int i=right;i>=left;i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            if(top>bottom)
                break;
            for(int i=bottom;i>=top;i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};