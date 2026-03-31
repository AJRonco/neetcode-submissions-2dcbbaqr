class Solution {

private:
    vector<pair<int,int>> coordinates{{0,1}, {1,0}, {-1,0}, {0,-1}};
public:


    void dfs(vector<vector<int>>& grid, int& finalArea, int row, int col) {

            if (row < 0 || row >= grid.size() ||
                col < 0 || col >= grid[0].size() || 
                grid[row][col] == 0) {
                return;
                }

            finalArea++;
            grid[row][col] = 0;
            for (auto& cord : coordinates) {
                dfs(grid, finalArea, row+cord.first, col+cord.second);
            }



    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxArea = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                int finalArea = 0;         
                dfs(grid, finalArea, i, j);

                if (finalArea > maxArea) {
                    maxArea = finalArea;
                }

                }

            }

        return maxArea;
        }
};
