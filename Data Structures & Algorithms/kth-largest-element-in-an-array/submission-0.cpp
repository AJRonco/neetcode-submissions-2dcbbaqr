class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        /*
        for num : nums
            maxHeap.push()
            if (maxHeap.size()> k  ){
                maxHop.pop}
            while(maxHeap size > 1)
                pop
                return maxHeapTop
        */



        for (auto num: nums) {
            minHeap.push(num);

            if (minHeap.size() > k) {
                minHeap.pop();
            }


        }


        return minHeap.top();
    }
};
