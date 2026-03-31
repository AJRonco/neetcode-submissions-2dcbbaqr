class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        


std::stack<int> tokenStack;
int var1{ 0 };
int var2{ 0 };

for (auto& x : tokens) {

	if (x == "+") {
		var1 = tokenStack.top();
		tokenStack.pop();
		var2 = tokenStack.top();
		tokenStack.pop();
		int result = var2 + var1;
		tokenStack.push(result);

	}
	else if (x == "-") {
		var1 = tokenStack.top();
		tokenStack.pop();
		var2 = tokenStack.top();
		tokenStack.pop();
		int result = var2 - var1;
		tokenStack.push(result);

	}
	else if (x == "*") {
		var1 = tokenStack.top();
		tokenStack.pop();
		var2 = tokenStack.top();
		tokenStack.pop();
		int result = var2 * var1;
		tokenStack.push(result);

	}
	else if (x == "/") {
		var1 = tokenStack.top();
		tokenStack.pop();
		var2 = tokenStack.top();
		tokenStack.pop();
		int result = var2 / var1;
		tokenStack.push(result);

	}

	else {
		tokenStack.push(std::stoi(x));
	}


}

return tokenStack.top();
    }
};
