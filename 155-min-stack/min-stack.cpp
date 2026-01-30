class MinStack {
public:
    vector<vector<int>> stack;

    MinStack() {
        
    }
    
    void push(int val) {
        int min = getMin();
        if (stack.empty() || min > val) min = val;
        stack.push_back({val, min});
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        if (stack.empty()) return -1;
        return stack.back()[0];
    }
    
    int getMin() {
        if (stack.empty()) return -1;
        return stack.back()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */