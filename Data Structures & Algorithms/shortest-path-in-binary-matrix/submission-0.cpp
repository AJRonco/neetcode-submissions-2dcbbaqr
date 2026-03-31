class Solution {
public:

//auto [row, col, length] = queue.top();


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        

        if (grid[0][0] == 1) {
            return -1;
        }


        queue<tuple<int,int,int>> cordQueue;
        vector<pair<int,int>> coordinates{{1,0},{0,1},{-1,0},{0,-1},
                                          {1,1},{-1,-1},{1,-1},{-1,1}};

        vector<vector<bool>> visitedCells(grid.size(), vector<bool>(grid[0].size(), false));
        int minLength = 0;

        cordQueue.push({0,0,1});
        visitedCells[0][0] = true;

        while(!cordQueue.empty()){
            auto [row, col, length] = cordQueue.front();
            cordQueue.pop();

            if (row == grid.size()-1 && col == grid[0].size()-1) {
                return length;
            }

            for (auto cord : coordinates) {
                int newRow = row + cord.first;
                int newCol = col + cord.second;

                if (newRow >= 0 && newRow < grid.size() &&
                    newCol >= 0 && newCol < grid[0].size() &&
                    grid[newRow][newCol] == 0 && visitedCells[newRow][newCol] == false) {

                        cordQueue.push({newRow, newCol, length+1});
                        visitedCells[newRow][newCol] = true;

                    }
            }
        }






        return -1;
    }
};