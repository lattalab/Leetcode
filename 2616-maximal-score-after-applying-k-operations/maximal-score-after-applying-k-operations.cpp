class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // set up priority queue
        priority_queue<int, vector<int>, less<int>> pq;
        for (int i=0; i<nums.size(); i++) pq.push(nums[i]);

        // greedy
        long long score = 0;
        while (k--) {
            int x = pq.top();
            cout << x <<endl;
            pq.pop();
            score += x;
            pq.push( ceil((double)x/3) );
        }

        return score;
    }
};