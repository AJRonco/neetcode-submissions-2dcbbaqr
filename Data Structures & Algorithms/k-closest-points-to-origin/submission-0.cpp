class Solution {
public:

    priority_queue<pair<double, vector<int>>> maxHeap;


    double distFromOrigin(int x, int y) {
        
        double distance = sqrt(   
        pow(x, 2.0) + 
        pow(y, 2.0));
        
        return distance;
        

    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        
        vector<vector<int>> res;

        for (auto pair: points) {

            double distance = distFromOrigin(pair[0], pair[1]);
            
            maxHeap.push({distance, pair});
        }

        while(maxHeap.size() > k) {
            maxHeap.pop();
        }

        while(!maxHeap.empty()){
            auto pair = maxHeap.top();
            maxHeap.pop();
            res.push_back(pair.second);
        }


        return res;


        


    }
};
