// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        if (pairs.empty()){
            return {};
        }
        vector<vector<Pair>> res;
        for (int i = 1; i < pairs.size(); i++){
            auto currentPair = pairs[i];
            int key = currentPair.key;
            int j = i - 1;
            res.push_back(pairs);
            while (j >= 0 && pairs[j].key > key) {
                pairs[j+1] = pairs[j];
                j--;
                
            }
            
            pairs[j+1] = currentPair;
            
        }
        res.push_back(pairs);

        return res;
    }
    
};
