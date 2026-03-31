class Solution {

    vector<pair<int,int>> cords = {{1,0},{0,1},{-1,0},{0,-1}};
public:
    bool exist(vector<vector<char>>& board, string word) {


        for (int row = 0; row < board.size(); row++){
            for (int col = 0; col < board[0].size(); col++){
                if (board[row][col] == word[0]){
                    if (dfs(board, word, row, col, 1)) return true;
                }
            }
        }

        return false;
    }


    bool dfs(vector<vector<char>>& board, string word, int row, int col, int index){

        if (index == word.size()){
                        return true;
        }

        char temp = board[row][col];
        board[row][col] = '#';

        for (auto cord : cords){

            int newRow = cord.first + row;
            int newCol = cord.second + col;

            if (newRow >= 0 && newRow < board.size() &&
                newCol >= 0 && newCol < board[0].size() &&
                board[newRow][newCol] == word[index]) {

                if (dfs(board, word, newRow, newCol, index+1)) {
                    board[row][col] = temp;
                    return true;
                }      
            }
        }
        board[row][col] = temp;
        return false;

    }
};

