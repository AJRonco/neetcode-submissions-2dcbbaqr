class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n, 0);
        vector<int>suff(n, 0);

        for (int i = 1; i < pref.size(); i++){
            pref[i] = pref[i-1] + nums[i-1];
        }
        for (int i = nums.size()-2; i >= 0; i--){
            suff[i] = suff[i+1] + nums[i+1];
        }


        for (int i = 0; i < pref.size(); i++){
            if (pref[i] == suff[i]){
                return i;
            }
        }

        return -1;


    }
};