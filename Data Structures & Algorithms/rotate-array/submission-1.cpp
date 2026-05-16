class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        vector<int>res(nums.size());

     int rotations = k % nums.size();

    

     for (int i = 0; i < nums.size(); i++){
        int index = (i + rotations) % nums.size();
        res[index] = nums[i];

     }

     nums = res;
    }
};