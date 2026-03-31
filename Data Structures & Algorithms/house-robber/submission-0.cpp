class Solution {
    unordered_map<int, int> memo;
public:
    int rob(vector<int>& nums) {
        return robHouse(nums, 0);


    }

    int robHouse(vector<int>& nums, int i) {
        
        if (i >= nums.size()) {
            return 0;
        }
        if (memo.count(i)) {
            return memo[i];
        }

        memo[i] =  max(robHouse(nums, i + 1), nums[i] + robHouse(nums, i+2));

        return memo[i];



    }
};
