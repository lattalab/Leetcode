class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        // store index
        vector<int> result(n, -1);
        stack<int> st;
        st.push(0);
        for (int i=1; i<n*2; i++) {
            int idx = i % n;    // real index
            if (nums[st.top()] >= nums[idx]) {
                st.push(idx);
            }
            else {
                while (!st.empty() && nums[st.top()] < nums[idx]) {
                    result[st.top()] = nums[idx];
                    st.pop();
                }
                st.push(idx);
            }
        }
        return result;
    }
};