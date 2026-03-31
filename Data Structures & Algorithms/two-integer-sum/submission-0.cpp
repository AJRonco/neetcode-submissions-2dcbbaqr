class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        for (int i = 0; i < nums.size(); i++) {

            int right = i + 1;

            while (right < nums.size()) {
                if ((nums[i] + nums[right]) == target) {
                    return {i, right};


                }
                else right++;

            }
        }
        return {};
    }
};
