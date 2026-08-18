class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums2.size();
        // connect with 2 arrays
        vector<pair<int, int>> v;
        for (int i=0; i<n; i++) {
            v.push_back({nums1[i], nums2[i]});
        }
        // sort based on nums2
        sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
                if (a.second == b.second) {
                    return a.first > b.first;
                }
                return a.second > b.second;
        });

        // pop the minimum until size is equal to k
        priority_queue<int, vector<int>, greater<int>> pq;  // min heap
        long long sum = 0;
        long long ans = 0;
        // the first half k-1 element just maintain sum for nums1
        for (int i=0; i<k-1; i++) {
            sum += v[i].first;
            pq.push(v[i].first);
        }
        // next loop invariant: push new element, then pop element
        for (int i=k-1; i<n; i++) {
            sum += v[i].first;
            pq.push(v[i].first);

            // since nums2 was sorted in decreasing number, always meet the minimum in following loop
            ans = max(ans, sum * v[i].second);

            // remove the smaller number, try to make total larger
            sum -= pq.top();
            pq.pop();
        }

        return ans;
    }
};