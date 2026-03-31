class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int cols = matrix[0].size()-1;
        
        int topRow = 0;
        int botRow = (int)matrix.size() - 1;
        int finalRow = -1;

        if (matrix.size() == 0) {
            return false;
        }

        while (topRow <= botRow && finalRow == -1) {
            int midRow = topRow + (botRow - topRow) / 2;


            if (matrix[midRow][0] <= target && matrix[midRow][cols] >= target) {
                finalRow = midRow;
            }

            else if (matrix[midRow][0] > target) {
                 botRow = midRow -1;
            }
            else if (matrix[midRow][0] < target) {
               
                topRow = midRow +1;
            }

            else {break;}
        }
        if (finalRow == -1) {
            return false;
        }
        int left = 0;
        int right = matrix[finalRow].size()-1;

        while (left <= right) {
            int mid = (left + right) /2;
    
            if (target > matrix[finalRow][mid]) {
                left = mid + 1;
            }
            else if (target < matrix[finalRow][mid]) {
                right = mid -1;
            }
            else {
                return true;
            }

        }

        return false;

        
    }
};