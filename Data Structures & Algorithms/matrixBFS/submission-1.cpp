class Solution {
public:
    int shortestPath(vector<vector<int>>& grid) {

        if (grid.empty() || grid[0][0] == 1){
            return -1;
        }
        if (grid.size() == 1 && grid[0].size() == 1) {
            return 0;
        }
        vector<pair<int,int>> cords{{1,0},{0,1},{-1,0},{0,-1}};
        int cycles = 0;
        queue<pair<int,int>> q;

        q.push({0,0});
        grid[0][0] = 1;

        while (!q.empty()){
            int size = q.size();
            cycles++;
            for (int i = 0; i < size; i++){

                auto currentPair = q.front();
                q.pop();
                for (auto cord : cords){
                int newRow = currentPair.first + cord.first;
                int newCol = currentPair.second + cord.second;

                if (newRow >= 0 && newRow < grid.size() &&
                    newCol >=0 && newCol < grid[0].size() &&
                    grid[newRow][newCol] == 0){

                        if (newRow == grid.size()-1 && newCol == grid[0].size()-1){
                            return cycles;
                         }
                        printf("adding row:%d,col:%d to q\n", newRow, newCol);
                        grid[newRow][newCol] = 1;
                        q.push({newRow,newCol});
                    }
            }
            }
            

            
            
            
            

            
        }

        return -1;


    }
};
