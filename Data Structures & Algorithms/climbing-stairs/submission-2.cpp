class Solution {
public:
    int climbStairs(int n) {
        std::map<int, int> memo;
        int finalCount = climbStairsRecursive(n, memo);
        return finalCount;
    }
    int climbStairsRecursive(int n, std::map<int, int>& memo) {

        if (memo.count(n) != 0) {
            return memo[n];
        }
        if (n==1) {
            return 1;
        }
        if (n==2) {
            return 2;
        }

        memo[n] = climbStairsRecursive(n-1, memo) + climbStairsRecursive(n-2, memo);

        return memo[n];
    }

    
};
