class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        // remove redundant
        for (int i=0; i<nums.size(); i++) st.insert(nums[i]);

        int ans = 0;
        for (int element : st) {
            // if n-1 is not in set, srart length = 1 from this element
            if (st.find(element -1) == st.end()) {
                int length = 1;

                while (st.find(element + length) != st.end()) {
                    length++;
                }

                ans = max(ans, length);
            }
        }
        return ans;
    }
};