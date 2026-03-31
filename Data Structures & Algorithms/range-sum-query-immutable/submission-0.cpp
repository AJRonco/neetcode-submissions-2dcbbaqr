class NumArray {
    private:
        vector<int> m_prefix;
public:
    NumArray(vector<int>& nums) {
        int total = 0;
        for (auto& n : nums){
            total+=n;
            m_prefix.push_back(total);

        }
    }
    
    int sumRange(int left, int right) {
        
        int pRight = m_prefix[right];
        int pLeft = left > 0 ? m_prefix[left-1] : 0;

        return pRight - pLeft;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */