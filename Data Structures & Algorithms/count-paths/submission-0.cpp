class Solution {
private:
    map<pair<int, int>, int> memo;
public:
    int uniquePaths(int m, int n) {
        
        return recursiveMaze(0, 0, m, n);
    }

    int recursiveMaze(int row, int col, int m, int n) {

        if (memo.count({row,col})){
            return memo[{row,col}];
        }

        if (row > m-1 || col > n-1) {
            return 0;
        }

        if  (row == m-1 && col == n-1) {
            return 1;
        }
    

        memo[{row, col}] = recursiveMaze(row + 1, col, m, n) + recursiveMaze(row, col+1, m, n);

        return memo[{row,col}];
    }
};
