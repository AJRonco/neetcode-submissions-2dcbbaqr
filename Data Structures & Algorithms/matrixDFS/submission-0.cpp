class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        vector<pair<int,int>> cords{{1,0},{0,1},{-1,0},{0,-1}};
        return dfs(grid, cords, 0, 0);
    }


    int dfs(vector<vector<int>>& grid, vector<pair<int,int>>& cords, int row, int col){

        if (row < 0 || row >= grid.size() ||
            col < 0 || col >= grid[0].size() || grid[row][col] == 1){
                return 0;
            }

        if (row == grid.size()-1 && col == grid[0].size()-1) {
            return 1;
        }

        int total_sum = 0;
        grid[row][col] = 1;        
        for (auto cord: cords) {
            total_sum += dfs(grid, cords, row+cord.first, col+cord.second);
        }
        grid[row][col] = 0;

        return total_sum;

    }
};
