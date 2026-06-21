class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        // 1. finding the maximum
        int max_val = 0;
        for (int i=0; i<n; i++) max_val = max(max_val, costs[i]);
        // 2. create a array of size max+1;
        vector<int> cnt(max_val+1, 0);
        // 3. traverse the original list and counting the frequency
        for (int i=0; i<n; i++) cnt[costs[i]]++;
        // 4. calculate the prefix sum
        for (int i=1; i<max_val+1; i++) cnt[i] = cnt[i-1] + cnt[i];
        // 5. sorting the array
        vector<int> res(n, 0);
        for (int i=n-1; i>=0; i--) {
            res[cnt[costs[i]] - 1] = costs[i];
            cnt[costs[i]]--;
        }
        // 6. traverse the answer and find the maximum number of ice cream
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (coins >= res[i]) {
                coins -= res[i];
                ans++;
            }
        }
        return ans;
    }
};