class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> nCount;

        for  (auto n : nums){
            nCount[n]++;

            if (nCount[n] > 1){
                return n;
            }
        }
    }
};
