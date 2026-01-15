class MedianFinder {
public:
    priority_queue<int> lowerHalf; // max-heap
    // contain medium -> (min heap) - (max heap) <= 1
    priority_queue<int, vector<int>, greater<int>> upperHalf; // min-heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (!lowerHalf.empty() && num < lowerHalf.top()) {
            lowerHalf.push(num);
        } 
        else {
            upperHalf.push(num);
        }
        
        // balanced heap size
        // e.g: [5, 4, 3, 2] -> put into lowerHalf
        // e.g: [1, 5, 10, 9, 2]
        if (lowerHalf.size() > upperHalf.size()) {
            upperHalf.push(lowerHalf.top());
            lowerHalf.pop();
        }
        // upper is too big.
        if (upperHalf.size() > lowerHalf.size() + 1) {
            lowerHalf.push(upperHalf.top());
            upperHalf.pop();
        }
    }
    
    double findMedian() {
        if (lowerHalf.size() == upperHalf.size()) 
            return (double)(lowerHalf.top() + upperHalf.top()) / 2.0;
        else
            return (double)upperHalf.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */