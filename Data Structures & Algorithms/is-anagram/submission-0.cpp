class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.length() != t.length()) {
            return false;
        }

        std::map<char, int> charCountS;
        std::map<char, int> charCountT;


        for (int i = 0; i < s.length(); i++) {
                charCountS[s[i]]++;
                charCountT[t[i]]++;
            
        }
        return charCountS == charCountT;
    }
};
