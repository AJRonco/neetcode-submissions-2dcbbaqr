class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int curSum = 0;
        unordered_map<int, int> pMap;
        pMap[0] = 1;


        for (int num: nums){
            curSum += num;
            int diff = curSum - k;
            res += pMap[diff];
            pMap[curSum]++;
        }

        return res;
    }
};