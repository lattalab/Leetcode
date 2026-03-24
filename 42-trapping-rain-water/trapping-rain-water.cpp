class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0 ;

        stack<int> st;
        st.push(0);
        for (int i=1; i<height.size(); i++) {
            if (height[i] <= height[st.top()]) {
                st.push(i);
            }
            else {
                while (!st.empty() && height[i] > height[st.top()]) {
                    // find the rightmost first bigger value
                    int mid = height[st.top()];
                    st.pop();
                    if (!st.empty()) {
                        int w = i - st.top() - 1;
                        // find minimum value of left and right side height
                        int h = min(height[st.top()], height[i]) - mid;
                        ans += (h * w);
                    }
                }
                st.push(i);
            }
        }
        return ans;
    }
};