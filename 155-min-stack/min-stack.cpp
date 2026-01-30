class MinStack {
public:
    long long stack[30010];
    int TOP = 0;
    long long min_value;

    MinStack() {
        
    }
    
    void push(int val) {
        if (TOP == 0) {
            stack[TOP++] = 0;
            min_value = val;
        }
        else {
            long long diff = (long long)val - min_value;
            stack[TOP++] = diff;
            if (diff < 0)
                min_value = val;
        }
    }
    
    void pop() {
        long long diff = stack[TOP-1];
        TOP--;
        if (diff < 0) min_value = (long long)min_value - diff;
    }
    
    int top() {
        long long diff = stack[TOP - 1];
        if (diff >= 0)
            return min_value + diff;
        else
            return min_value;
    }
    
    int getMin() {
        return (int)min_value;
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