class Solution {

    private:
        vector<pair<int,int>> cords = {{1,0},{0,1},{-1,0},{0,-1}};
public:
    int countPaths(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()){
            return 0;
        }
        return dfs(grid, 0, 0);
    }


    int dfs(vector<vector<int>>& grid, int row, int col){

        if (row < 0 || row > grid.size()-1 ||
            col < 0 || col > grid[0].size()-1 ||
            grid[row][col] == 1) {
                return 0;
            }

        if (row == grid.size()-1 && col == grid[0].size()-1){
            return 1;
        }

        grid[row][col] = 1;
        int totalSum = 0;

        for (auto& cord: cords){
            totalSum = totalSum + dfs(grid, row+cord.first, col+cord.second);
        }

        grid[row][col] = 0;
        return totalSum;

    }
};
