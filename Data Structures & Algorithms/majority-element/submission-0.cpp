class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int check = nums.size() / 2;

        for (auto n: nums){
            m[n]++;

            if (m[n] > check){
                return n;
            }
        }
    }
};