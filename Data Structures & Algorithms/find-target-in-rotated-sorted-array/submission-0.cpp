class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        [3,4,5,6,1,2]
        [5,6,1,2,3,4]
        */

        /*
        find pivot
        binarysearch(left)
            if not -1
                retrun res
        
        return binarysearch(right)
        */
        int left = 0;
        int right = nums.size()-1;

        while (left < right){

            int mid = (left + right) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }


        }
        int pivot = left;

        int result = binarySearch(nums, target, 0, pivot);

            if (result != -1){
                return result;
            }
        
        return binarySearch(nums, target, pivot, nums.size()-1);
        
    }

    int binarySearch(vector<int>& nums, int target, int left, int right){
        int l = left;
        int r = right;


        while (l <= r){
            int mid = l + (r - l) / 2;

            if (nums[mid] == target){
                return mid;
            }

            else if (nums[mid] > target){
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return -1;
    }
};
