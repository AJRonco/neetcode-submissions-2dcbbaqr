class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0;
        int R = numbers.size()-1;
        vector<int> res;
        while (L < R) {

            if (numbers[L] + numbers[R] == target){
                res.push_back(L+1);
                res.push_back(R+1);
                break;
            }
            else if (numbers[L] + numbers[R] > target){
                R--;
            }
            else {
                L++;
            }
        }
        return res;
       
        
    }
};
