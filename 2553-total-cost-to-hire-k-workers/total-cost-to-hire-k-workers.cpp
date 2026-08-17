class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> left, right;
        int n = costs.size();
        // maintain 2 heap array,
        // index i and j means valid successor for next elment to push
        for (int i=0; i<candidates; i++) left.push(costs[i]);
        for (int j=max(candidates, n-candidates); j<n; j++) right.push(costs[j]);

        // compare 2 element
        long long ans = 0;
        int nextHead = candidates;
        int nextTail = n - 1 - candidates;
        for (int i=0; i<k; i++) {
            // note that <= due to tie worker
            if ( right.empty() || (!left.empty() && !right.empty() && left.top() <= right.top()) ) {
                ans += left.top();
                left.pop();

                // refill when there exist worker
                if (nextHead <= nextTail) {
                    left.push(costs[nextHead]);
                    nextHead++;
                }
            }
            else {
                ans += right.top();
                right.pop();

                // refill when there exist worker
                if (nextHead <= nextTail) {
                    right.push(costs[nextTail]);
                    nextTail--;
                }
            }
        }

        return ans;
    }
};