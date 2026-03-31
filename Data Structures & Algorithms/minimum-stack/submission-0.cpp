class MinStack {

private:

std::vector<int> classStack;
std::vector<int> minStack;

public:


    MinStack() {
        
    }
    
    void push(int val) {
        classStack.push_back(val);

        if (minStack.empty()) {
            minStack.push_back(val);
        }
        else {
            val = std::min(val, minStack[minStack.size()-1]);
            minStack.push_back(val);
        }
        
        
    }
    
    void pop() {
        classStack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return classStack[classStack.size()-1];
    }
    
    int getMin() {
        return minStack[minStack.size()-1];  
    }
};
