class KthLargest {

private:
 int largest;
 std::priority_queue<int> maxHeap;

public:



    KthLargest(int k, vector<int>& nums) {
        for (auto num:nums) {
            maxHeap.push(num);
        }
        largest = k;
    }
    
    int add(int val) {
        maxHeap.push(val);
        auto copyHeap = maxHeap;

        for (int i = 1; i < largest; i++) {
            copyHeap.pop();


        }

        return copyHeap.top();
        
    }
};
