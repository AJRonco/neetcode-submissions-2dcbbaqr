class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> cordQueue;
        vector<pair<int,int>> coordinates{{1,0},{0,1},{-1,0},{0,-1}};
        int fresh = 0;
        int time = 0;

        for(int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1) {
                    fresh++;
                }
                if (grid[i][j] == 2) {
                    cordQueue.push({i,j});
                }
            }
        }


        while (fresh > 0 && !cordQueue.empty()) {
            int length = cordQueue.size();

            for(int i = 0; i < length; i++){
                auto curr = cordQueue.front();
                cordQueue.pop();
                int row = curr.first;
                int col = curr.second;

                for(auto cord: coordinates){
                    int newRow = row + cord.first;
                    int newCol = col + cord.second;

                    if (newRow >= 0 && newRow < grid.size() &&
                        newCol >=0 && newCol < grid[0].size() &&
                        grid[newRow][newCol] == 1) {
                            grid[newRow][newCol] = 2;
                            cordQueue.push({newRow,newCol});
                            fresh--;
                        }
                }
                
            }
            time++;
            
        }

        return fresh == 0 ? time : -1;



    }
};
