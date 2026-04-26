class Solution {
    private:
    vector<pair<int,int>> cords = {{0,1},{1,0},{-1,0},{0,-1}};
public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> p_reachable(rows, vector<bool>(cols, false));
        vector<vector<bool>> a_reachable(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            dfs(i, 0, heights, p_reachable);
            dfs(i, cols - 1, heights, a_reachable);
        }
        for (int j = 0; j < cols; j++) {
            dfs(0, j, heights, p_reachable);
            dfs(rows - 1, j, heights, a_reachable);
        }

        vector<vector<int>> res;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (p_reachable[i][j] && a_reachable[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& reachable){
        reachable[row][col] = true;
        for (auto cord : cords){
            int newRow = row + cord.first;
            int newCol = col + cord.second;

            if (newRow >= 0 && newRow < heights.size() &&
                newCol >= 0 && newCol < heights[0].size() &&
                !reachable[newRow][newCol] && heights[newRow][newCol] >= heights[row][col]){
                dfs(newRow, newCol, heights, reachable);
            }
        }
    }
};