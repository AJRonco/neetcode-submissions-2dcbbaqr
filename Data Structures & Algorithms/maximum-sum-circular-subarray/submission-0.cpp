class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globMax = nums[0];
        int globMin = nums[0];
        int curMax = 0;
        int curMin = 0;
        int total = 0;

        for (auto n: nums){

            curMax = max(curMax + n, n);
            curMin = min(curMin + n, n);
            total += n;
            globMax = max(curMax, globMax);
            globMin = min(curMin, globMin);
            
        }

        return globMax > 0 ? max(globMax, total-globMin) : globMax;
    }
};