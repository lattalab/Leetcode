class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size = q.size();
        for (int i=0; i<size-1; i++) {
            int val = q.front();
            q.pop();
            this->push(val);
        }
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.back();
        // or
        // int val = this->pop();
        // this->push(val);
        // return val;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */