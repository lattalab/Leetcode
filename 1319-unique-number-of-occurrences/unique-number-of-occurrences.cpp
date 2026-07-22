class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        // scan the order
        for (auto num : arr) {
            mp[num]++;
        }
        // find if unique
        unordered_set<int> st;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int times = it->second;
            if (st.count(times)) {
                return false;
            }
            else {
                st.insert(times);
            }
        }
        return true;
    }
};