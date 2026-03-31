class KthLargest {

private:
 int largest;
 std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

public:



    KthLargest(int k, vector<int>& nums) {
        this->largest = k;
        for(int num:nums){
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
       minHeap.push(val);
       if (minHeap.size() > largest) {
            minHeap.pop();
       }
       return minHeap.top();
        
    }
};
