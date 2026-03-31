class MedianFinder {

    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if (minHeap.empty()){
            minHeap.push(num);
        }

        else if (num > minHeap.top()){
            minHeap.push(num);
        }
        /*
        min     max
        1       2
        
        */
        else {
            maxHeap.push(num);
        }

        if (minHeap.size() > maxHeap.size() + 1){
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }
        else if (maxHeap.size() > minHeap.size() + 1){
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
    }
    
    double findMedian() {


        if (maxHeap.size() == minHeap.size()){
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }

        else {
            if (maxHeap.size() > minHeap.size()){
                return (double)maxHeap.top();
            }

            else {
                return (double)minHeap.top();
            }
        }
    }
};
