class Solution {
public:
    bool isValid(string s) {

        std::vector<char> charStack;

        for (int i = 0; i < s.size(); i++) {
            char currentChar = s[i];

            if (currentChar == '(' || currentChar == '{' ||currentChar == '[') {
                charStack.push_back(currentChar);
            }
            else {

                if (charStack.empty()){
                    return false;
                }

                if (currentChar == ')') {
                    if (charStack[charStack.size()-1] == '('){
                        charStack.pop_back();
                    }
                    else {
                        return false;
                    }
                }
                else if (currentChar == '}') {
                    if (charStack[charStack.size()-1] == '{'){
                        charStack.pop_back();
                    }
                    else {
                        return false;
                    }
                }
                else if(currentChar == ']') {
                    if (charStack[charStack.size()-1] == '['){
                        charStack.pop_back();
                    }
                    else {
                        return false;
                    }
                }

            }




        }
        return charStack.empty();

        
    }
};
