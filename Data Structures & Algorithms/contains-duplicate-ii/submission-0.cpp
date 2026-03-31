class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        if (k == 0){
            return 0;
        }
        unordered_map<int, int> nMap;
        int L = 0;
        for (int R = 0; R < nums.size(); R++){

            if (R - L > k){
                nMap[nums[L]]--;
                L++;
                
            }


            if (nMap[nums[R]] > 0){
                return true;
            }

            nMap[nums[R]]++;
            
        }
        return false;
    }
};