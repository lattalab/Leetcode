class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int l=0; l<n; l++) {
            unordered_set<int> st;
            // cnt[0] for even, cnt[1] for odd
            int cnt[2] = {0};
            for (int r=l; r<n; r++) {
                int x = nums[r];
                if ( st.find(x) == st.end() ) {
                    st.insert(x);
                    cnt[x%2]++;
                }
                // when num. of odd = num. of even
                if (cnt[0] == cnt[1]) {
                    ans = max(ans, r-l+1);
                }
            }
        }
        return ans;
    }
};