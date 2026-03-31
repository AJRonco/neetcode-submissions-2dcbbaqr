class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int L = 0;
        int totalSum = 0;
        int res = INT_MAX;

        for (int R = 0; R < nums.size(); R++){
            totalSum += nums[R];

            while (totalSum >= target){
                res = min((R - L + 1), res);
                totalSum -= nums[L];
                L++;
            }

        }

        return res == INT_MAX ? 0 : res;
    }
};