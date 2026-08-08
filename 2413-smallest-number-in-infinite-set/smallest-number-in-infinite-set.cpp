class SmallestInfiniteSet {
public:
    set<int> st;
    // min-heap
    priority_queue<int, vector<int>, greater<int>> pq;

    SmallestInfiniteSet() {
        // consider 1000 elements
        for (int i=1; i<=1000; i++) {
            st.insert(i);
            pq.push(i);
        }    
    }
    
    int popSmallest() {
        int num = pq.top();
        pq.pop();
        st.erase(num);
        return num;
    }
    
    void addBack(int num) {
        if (!st.count(num)) {
            st.insert(num);
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */