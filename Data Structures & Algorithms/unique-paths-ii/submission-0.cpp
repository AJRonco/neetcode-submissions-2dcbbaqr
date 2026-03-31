class Solution {

private:
    map<pair<int, int>, int> memo;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
       return recursiveMaze(obstacleGrid, 0, 0);

        
    }

    int recursiveMaze(vector<vector<int>>& obstacleGrid, int row, int col) {

        if (memo.count({row,col})){
            return memo[{row,col}];
        }

        if (row > obstacleGrid.size()-1 || col > obstacleGrid[0].size()-1) {
            return 0;
        }

        if (obstacleGrid[row][col] == 1){
            return 0;
        }

        if (row == obstacleGrid.size()-1 && col == obstacleGrid[0].size()-1){
            return 1;
        }

        memo[{row,col}] = recursiveMaze(obstacleGrid, row + 1, col) + recursiveMaze(obstacleGrid, row, col + 1);
        return memo[{row,col}];

    }
};