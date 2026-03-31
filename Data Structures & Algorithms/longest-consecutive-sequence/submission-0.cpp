class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
        2,3,4,4,5,10,20
        */
        unordered_map<int, int> m;

        for (auto& num : nums) {
            m[num]++;
        }

        int max = 0;

        for (auto& num : m){
            int cur = num.first;
            if (!m.count(cur-1)){
                int count = 0;
                while(m.count(cur)){
                    count++;
                    cur+=1;
                }
                if (count > max) max = count;

            }
        }
        return max;
    }
};
