class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        if (position.empty()){
            return 0;
        }

        if (position.size() == 1){
            return 1;
        }
        
        vector<pair<int, float>> vehicles;
        for (int i = 0; i < position.size(); i++){
            // {position, time to end}
            vehicles.push_back({position[i], (float)(target - position[i]) / (float)speed[i] });
        }
        sort(vehicles.begin(), vehicles.end());

        vector<float> stack;
        for (int i = vehicles.size() - 1; i >= 0; i--) {
            float currentTime = vehicles[i].second;
            if (stack.empty() || currentTime > stack.back()) {
                stack.push_back(currentTime);
            }
        }

        return stack.size();
    }
};