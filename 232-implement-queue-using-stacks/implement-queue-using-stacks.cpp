class MyQueue {
public:
    stack<int> st_in;
    stack<int> st_out;
    MyQueue() {
        
    }
    
    void push(int x) {
        st_in.push(x);
    }
    
    int pop() {
        if (st_out.empty()) {
            while (!st_in.empty()) {
                int val = st_in.top();
                st_in.pop();
                st_out.push(val);
            }
        }
        int result = st_out.top();
        st_out.pop();
        return result;
    }
    
    int peek() {
        int result = this->pop();
        st_out.push(result);
        return result;
    }
    
    bool empty() {
        return st_in.empty() && st_out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */