class Solution {
public:
    struct comparator{
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second < rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. calculating frequency
        map<int, int> mp;
        for (int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        // 2. using max-heap to store pair
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
        for (auto it=mp.begin(); it!=mp.end(); it++){
            // pair format: {elements, frequency}
            pq.push({it->first, it->second});
        }

        // 3. fetch top K
        vector<int> res;
        while(k--){
            int val = (pq.top()).first;
            pq.pop();
            res.push_back(val);
        }

        return res;
    }
};