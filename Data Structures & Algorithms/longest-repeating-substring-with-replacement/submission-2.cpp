class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> charCount;
        int l = 0;
        int maxSub = 0;
        int maxFreq = 0;
        int r = 0;

        while(r < s.size()){
            charCount[s[r]]++;
            maxFreq = max(maxFreq, charCount[s[r]]);
                /*
                "AAABABB", 
                k = 1
                */
            while((r - l + 1) - maxFreq > k){
                charCount[s[l]]--;
                l++; 
            }
            int curSub = r - l + 1;
            maxSub = max(maxSub, curSub);
            r++;
            
        }
        return maxSub;

    }
};
