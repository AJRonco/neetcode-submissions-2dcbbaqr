class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int, int>> tempStack;
std::vector<int> res(temperatures.size(), 0);


for (int i = 0; i < temperatures.size(); i++) {
	int currTemp = temperatures[i];

	while (!tempStack.empty() && currTemp > tempStack.top().first) {

		auto stackPair = tempStack.top();
		tempStack.pop();

		res[stackPair.second] = i - stackPair.second;
	}
	tempStack.push({ currTemp, i });
}


return res;
    }
};
