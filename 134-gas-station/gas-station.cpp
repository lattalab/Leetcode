class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int curSum = 0;
        int totalSum = 0;
        for (int i=0; i<gas.size(); i++) {
            curSum += (gas[i] - cost[i]);
            totalSum += (gas[i] - cost[i]);
            if (curSum < 0) {
                // greedy proof: if this region < 0, the start point will start from i+1
                start = i+1;
                curSum = 0;
            }
        }
        // when the remaining oil cannot offer the entire loop
        if (totalSum < 0) return -1;
        return start;
    }
};