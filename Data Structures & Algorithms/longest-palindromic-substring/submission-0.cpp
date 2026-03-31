class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int start = 0;
        

        for (int i = 0; i < s.length(); i++){

            int lenOne = maxSub(i, i, s);
            int lenTwo = maxSub(i, i+1, s);

            int curMax = max(lenOne, lenTwo);

            if (curMax > maxLen){

                maxLen = curMax; 
                start = i - (maxLen - 1) / 2;
            }
            


        }

        return s.substr(start, maxLen);
    }


    int maxSub(int left, int right, string& s){
            int l = left;
            int r = right;


            while (l >= 0 && r < s.length() && s[l] == s[r]){

                l--;
                r++;
            }


            return r - l - 1;



    }
};
