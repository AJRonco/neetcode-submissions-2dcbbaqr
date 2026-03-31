class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.empty()){
            return 0;
        }
        if (s.size() == 1) return 1;
        int l = 0;
        int r = 1;
        unordered_map<char, int> charMap;
        int maxSub = 1;
        charMap[s[l]]++;
        while (r < s.size()){
            if (charMap.count(s[r])){
                printf("found duplicate %c\n", s[r]);
                while (s[l] != s[r]){
                    printf("erasing duplicate %c\n", s[r]);
                    charMap.erase(s[l]);
                    l++;
                }
                r++;
                l++;

            }
            else{
                printf("adding %c to window\n", s[r]);
                charMap[s[r]]++;
                int cSub = r - l+1;
                maxSub = max(cSub, maxSub);
                r++;
                

            }

        }
        return maxSub;
    }
};
