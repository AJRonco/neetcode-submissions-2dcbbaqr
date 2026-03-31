class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::map<int, int> unique;


        for (int i = 0; i < nums.size(); i++){
            if (unique.count(nums[i]) != 0) {
                return true;
            }
            else {
                unique[nums[i]] = 1;
            }
        }

        return false;
    }
};