class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        unordered_map<char, int> pMap;
        unordered_map<char, int> sMap;
        int l = 0;
        int r = s1.size()-1;



        for (auto c : s1){
            pMap[c]++;
            //printf("perm map:%c\n", c);
        }

        for (int i = 0; i <= r; i++){
            sMap[s2[i]]++;
            //printf("adding to initial window: %c\n", s2[i]);

        }

        if (pMap == sMap){
            return true;
        }
        while(r < (int)s2.size() - 1){
            l++;
            r++;
            sMap[s2[l-1]]--;
            sMap[s2[r]]++;

            if (sMap[s2[l-1]] == 0) {
                sMap.erase(s2[l-1]);
                }

            
            if (pMap == sMap){
                return true;
            }

        }



    return false;   
    }
};
