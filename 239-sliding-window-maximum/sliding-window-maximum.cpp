class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        // store (index, val)
        deque<pair<int, int>> dq;

        for (int i=0; i<nums.size(); i++){
            int val = nums[i];

            // maintain the sliding window
            // k-1 is because "we don't count the next excepted push"
            while (!dq.empty() && dq.front().first <= i-k)
                dq.pop_front();

            // before push `val`, pop front any less than this val in the deque
            if (!dq.empty() && dq.front().second <= val )
                dq.pop_front();

            // maintain decreasing, and check back again
            // e.g 5, 3, 6 -> 6
            while (!dq.empty() && dq.back().second <= val)
                dq.pop_back();

            dq.push_back({i, val});

            // first end index of sliding window is k-1
            if (i >= k-1)
                ans.push_back(dq.front().second);
        }
        return ans;
    }
};