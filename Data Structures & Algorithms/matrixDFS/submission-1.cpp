class Solution {

    private:

    vector<pair<int,int>> cords = {{1,0},{0,1},{-1,0},{0,-1}};

public:
    int countPaths(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        vector<vector<bool>> visitedCells(grid.size(), vector<bool>(grid[0].size(), 0));

        return dfs(grid, visitedCells, 0, 0);
    }


    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visitedCells, int row, int col) {

        if (row < 0 || row > (int)grid.size()-1 ||
            col < 0 || col > (int)grid[0].size()-1 ||
            grid[row][col] == 1 || visitedCells[row][col])
            {
                return 0;
            }

        if (row == grid.size()-1 && col == grid[0].size()-1){
            return 1;
        }

        visitedCells[row][col] = 1;
        int total_sum = 0;

        for (auto& cord : cords){
            
            total_sum = total_sum + dfs(grid, visitedCells, row+cord.first, col+cord.second);
        }

        visitedCells[row][col] = 0;

        return total_sum;

    }
};
