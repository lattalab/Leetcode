class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        // push
        for (int i=0; i<stones.size(); i++) {
            pq.push(stones[i]);
        }
        // main logic
        while (pq.size() >= 2) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if (x > y) {
                x -= y;
                pq.push(x);
            }
            else if (x < y) {
                y -= x;
                pq.push(y);
            }
            else {
                pq.push(0);
            }
        }

        return pq.top();
    }
};