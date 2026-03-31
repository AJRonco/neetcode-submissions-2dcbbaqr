class Solution {
public:
    int maxArea(vector<int>& heights) {
        /*
        int left = 0;
        max area = 0;
        int right = heights.size()-1;
        while (l < r) {

            int currentArea = r - l * min(heights[l], heights[r]);

            if (currentArea > maxArea) {
                maxArea = current}

            if (r < l)
                move right--
            else
                move left++
        }
        */

        int l = 0;
        int maxArea = 0;
        int r = heights.size()-1;

        while (l <= r){
            int currentArea = (r - l) * min(heights[l], heights[r]);
            

            if (currentArea > maxArea){
                maxArea = currentArea;
            }

            if (heights[r] < heights[l]){
                r--;
            }
            else {
                l++;
            }
        }
        return maxArea;
    }
};
