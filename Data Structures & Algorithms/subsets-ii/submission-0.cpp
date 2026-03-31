class Solution {
    private:

    map<vector<int>, int> nMap;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res; 
        vector<int> subset;
        nMap.clear();
        subSetHelper(nums, 0, subset);

        for (auto& pair : nMap){
            res.push_back(pair.first);
        }

        return res;

    }


    void subSetHelper(vector<int>& nums, int i, vector<int> subset){

            if (i >= nums.size()) {
                nMap[subset]++;
                return;
            }
            subset.push_back(nums[i]);
            subSetHelper(nums, i+1, subset);
            subset.pop_back();
            subSetHelper(nums, i+1, subset);

            }
};
