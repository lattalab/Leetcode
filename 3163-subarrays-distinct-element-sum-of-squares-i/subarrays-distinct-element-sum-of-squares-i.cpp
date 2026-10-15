class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            int count = 0;
            unordered_set<int> st;
            for (int j=i; j<nums.size(); j++) {
                if(!st.count(nums[j])) {
                    st.insert(nums[j]);
                    count += 1;
                }
                ans += count * count;
            }
        }
        return ans;
    }
};