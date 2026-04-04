class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size();
        int row = matrix.size();
        int L = 0, R = row-1;
        while(L <= R)
        {
            int mid = (L+R) / 2;
            if(target < matrix[mid][0]) R--;
            else if(target > matrix[mid][col-1]) L++;
            else break;  
        }

        int m = (L+R)/2;

        L = 0, R = col-1;
        while(L <= R)
        {
            int mid = (L+R)/2;
            if(matrix[m][mid] > target) R--;
            else if(matrix[m][mid] < target) L++;
            else return true;
        }
        return false;
    }
};
