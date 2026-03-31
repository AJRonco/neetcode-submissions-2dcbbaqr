class Solution {

    private:
    std::priority_queue<int> maxHeap;

public:
    int lastStoneWeight(vector<int>& stones) {
        
        for(auto x: stones){
            maxHeap.push(x);
        }

        while(maxHeap.size() >= 2){
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();

            if(y!=x){
                y -= x;
                maxHeap.push(y);
            }
             
        }

        if (maxHeap.size() == 1){
            return maxHeap.top();
        }
        else {
            return 0;
        }
    }
};
