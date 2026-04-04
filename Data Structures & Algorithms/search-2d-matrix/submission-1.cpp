class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cols = matrix[0].size();
        int rows = matrix.size();

        int L = 0, R = rows-1;
        while(L <= R)
        {
            int row = (L+R) / 2;
            if(target < matrix[row][0]) R = row-1;
            else if(target > matrix[row][cols-1]) L = row+1;
            else break;
        }

        int m = (L+R)/2;
        L = 0, R = cols-1;
        while(L <= R)
        {
            int mid = (L+R) / 2;
            if(matrix[m][mid] > target) R = mid-1;
            else if(matrix[m][mid] < target) L = mid+1;
            else return true;
        }
        return false;
    }
};
