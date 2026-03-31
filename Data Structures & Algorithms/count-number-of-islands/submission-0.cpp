class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int islandCount = 0;
        vector<pair<int,int>> coordinates{{1,0}, {0,1}, {-1,0}, {0,-1}};
 
        queue<pair<int,int>> islandQueue;
        //row
        for (int i = 0; i < grid.size(); i++){
            //col
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1') {
                islandCount++;
                islandQueue.push({i,j});
                }

                while(!islandQueue.empty()){
                    int currentRow = islandQueue.front().first;
                    int currentCol = islandQueue.front().second;
                    islandQueue.pop();
                    grid[currentRow][currentCol] = '0';

                    for (auto cord : coordinates) {
                        int newRow = currentRow + cord.first;
                        int newCol = currentCol + cord.second;

                        if (newRow >= 0 && newRow < grid.size() &&
                            newCol >=0 && newCol < grid[0].size()) {

                             if (grid[newRow][newCol] == '1'){
                                islandQueue.push({newRow,newCol});
                             }

                            }
                    }

                }




        
            }
        }

        return islandCount;


        
       /*
       queue pair coordinate
       vector<pair<row,col>> coordinates {{1,0}, {0,1}, {-1,0}, 0,-1}
       for cell in grid
            if cell is '1'
            islandcount++
            queue.push(pair for cell)


        while (!queue.empty()){
        
            mark this node '0'
            create coordinates for the surrounding
            for (coordinate in coordinates))
                newRow = currentRow + coordinateRow
                newCol = currentCol + coordinateCol
            }

            if (newRow >= 0 && newRow < grid.size
                newCol >= 0 && newCol < grid[0].size()
                && grid[newRow][newCol] == '1')
                {
                add to the queue
                }

       return islandcount
       */ 

       
    }
};
