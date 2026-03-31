class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxSum = INT_MIN;
        int curSum = 0;

        for (auto x: nums){
            curSum = max(curSum, 0);
            curSum += x;

            maxSum = max(curSum, maxSum);



        }

        return maxSum;
    }
};
