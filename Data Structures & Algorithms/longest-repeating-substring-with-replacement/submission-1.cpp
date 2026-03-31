class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> charMap;
        int maxSub = 0;
        int l = 0;
        int maxf = 0;
        for (int r = 0; r < s.size(); r++){

            charMap[s[r]]++;
            maxf = max(maxf, charMap[s[r]]);

            while ((r - l + 1) - maxf > k){
                charMap[s[l]]--;
                l++;
            }
            int curSub = r - l + 1;
            maxSub = max(maxSub, curSub);
        }

        return maxSub;

        
    }
};
