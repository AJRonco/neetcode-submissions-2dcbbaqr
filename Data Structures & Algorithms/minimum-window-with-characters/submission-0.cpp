class Solution {
public:
    string minWindow(string s, string t) {

        if (t.empty()){
            return "";
        }

        unordered_map<char,int> tMap;
        unordered_map<char,int> sMap;

        for (auto& c : t){
            tMap[c]++;

        }

        int l = 0;

        int have = 0;
        int need = tMap.size();
        int resLen = INT_MAX;
        bool valid = false;
        pair<int, int> res = {-1,-1};

        for (int r = 0; r < s.length(); r++){
            char c = s[r];
            sMap[c]++;

            if (tMap.count(c) && sMap[c] == tMap[c]){
                have++;
            }

            while (have == need){
                if ((r - l + 1) < resLen){
                    resLen = r - l + 1;
                    res = {l, r};
                }

                sMap[s[l]]--;
                if (tMap.count(s[l]) && sMap[s[l]] < tMap[s[l]]){
                    have--;
                }
                l++;
            }
            
        }
        return resLen == INT_MAX ? "" :
        s.substr(res.first, resLen);
    }
};
