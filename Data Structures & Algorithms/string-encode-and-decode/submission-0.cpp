class Solution {
public:

    string encode(vector<string>& strs) {

        if (strs.empty()){
            return "";
        }

        vector<int> sizes;

        for (auto& s : strs){
            sizes.push_back(s.size());
        }

        string res = "";

        for (auto& size : sizes){
            res += to_string(size) + ',';
        }

        res += '#';

        for (auto& s : strs){
            res += s;
        }

        return res;
    }

    vector<string> decode(string s) {

        if (s.empty()){
            return {};
        }



        vector<string> res;
        vector<int> sizes;
        int i = 0;

        while (s[i] != '#'){
            string current = "";

            while (s[i] != ',') {
                current += s[i];
                i++;
            }
            sizes.push_back(stoi(current));
            i++;
        } 
        i++;

        for (auto& size : sizes){
            res.push_back(s.substr(i, size));
            i += size;
        }

        return res;




    }
};
