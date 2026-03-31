class Solution {
public:
    /*
if (row empty or column empty)
if (row size 1 && col size 1)
cords
entry point {0,0}
mark entry as 1
int cycle 0
queue.empty()
    int length = queue.size()
    for (int i = 0; i < length; i++){
        cycle++
        pair = queue.front
        queue.pop
        for (auto cord: cords)
            new pair
            /*
            if new pair in bounds
            if new pair not a rock
            if new pair not 1

                if newpair is end
             mark cell as 1 
            and put in queue
                return cycle;
           
    }
*/
    int shortestPath(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return -1;
        }
        if (grid.size() == 1 && grid[0].size() == 1){
            return 0;
        }

        vector<pair<int,int>> cords={{0,1},{1,0},{-1,0},{0,-1}};

        queue<pair<int,int>> q;
        int cycle = 0;
        q.push({0,0});
        grid[0][0] = 1;

        while(!q.empty()){
            int length = q.size();
            cycle++;
            
            for (int i = 0; i < length; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (const auto& cord: cords) {
                    int newRow = row + cord.first;
                    int newCol = col + cord.second;
    
            
                    if (newRow >= 0 && newRow < grid.size() &&
                        newCol >= 0 && newCol < grid[0].size() &&
                        grid[newRow][newCol] == 0) {

                        if (newRow == grid.size()-1 && newCol == grid[0].size()-1){
                            return cycle;
                        }
                        grid[newRow][newCol] = 1;
                        q.push({newRow,newCol});
                        }
                }
            }
        }
        return -1;
    }
};



