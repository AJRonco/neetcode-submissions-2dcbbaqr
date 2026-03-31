/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int minNum = 1;
        int maxNum = n;

        while (minNum <= maxNum) {
            int mid = minNum + (maxNum - minNum) /2;
            int guessResult = guess(mid);

            if (guessResult == 1) {
                minNum = mid+1;
            }
            else if (guessResult == -1) {

                maxNum = mid-1;
            }
            else {
                return mid;
            }
        }
    }
};