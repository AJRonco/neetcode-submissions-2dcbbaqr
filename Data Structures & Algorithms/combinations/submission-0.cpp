class Solution {
    private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        dfs(1, n, k, cur);
        return res;
    }


    void dfs(int i, int n, int k, vector<int>& cur){



        if (cur.size()==k){
            res.push_back(cur);
            return;
        }

        if (i > n){
            return;
        }

        cur.push_back(i);
        dfs(i+1, n, k, cur);
        cur.pop_back();
        dfs(i+1, n, k, cur);
    }
};