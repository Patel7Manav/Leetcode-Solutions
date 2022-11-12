class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     vector<int>li;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                li.push_back(matrix[i][j]);
        if(binary_search(li.begin(),li.end(),target))
            return true;
        return false;
    }
};