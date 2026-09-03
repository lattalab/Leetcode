class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // push the initial pairs {nums1, nums2[0]}
        for (int num : nums1) {
            pq.push({num + nums2[0], 0});
        }

        while (k-- && !pq.empty()) {
            int sum = pq.top().first;
            int pos = pq.top().second;
            pq.pop();

            ans.push_back({sum-nums2[pos], nums2[pos]});
            
            if (pos + 1 < n2) {
                pq.push({sum - nums2[pos] + nums2[pos+1], pos+1});
            }
        }
        return ans;
    }
};