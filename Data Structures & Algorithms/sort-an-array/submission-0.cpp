class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> q;
        vector<int> res;
        for (auto n : nums){
            q.push(n);
        }

        while(q.size()){
            res.push_back(q.top());
            q.pop();
        }

        return res;
    }
};