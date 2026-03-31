class NumMatrix {
private: 

    vector<vector<int>> pMatrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        pMatrix = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));
        for (int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                pMatrix[i + 1][j + 1] = matrix[i][j] + pMatrix[i][j + 1] + pMatrix[i + 1][j] - pMatrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pMatrix[row2 + 1][col2 + 1] - pMatrix[row1][col2 + 1] - pMatrix[row2 + 1][col1] + pMatrix[row1][col1];
    }

};
 