class Solution {
    private:
    vector<vector<int>> res;
    map<vector<int>, int> nMap;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curVec;
        backtrack(candidates, target, 0, 0, curVec);

        for (auto n : nMap){
            res.push_back(n.first);
        }
        return res;
    }

    void backtrack(vector<int>& cand, int target, int i, int curSum, vector<int>& curVec){

        if (curSum == target){
            nMap[curVec]++;

            return;
        }

        if (curSum > target || i >= cand.size()){
            return;
        }

        curVec.push_back(cand[i]);
        backtrack(cand, target, i+1, curSum+cand[i], curVec);
        curVec.pop_back();

        while (i + 1 < cand.size() && cand[i] == cand[i+1]) i++;
        backtrack(cand, target, i+1, curSum, curVec);

    }
};

