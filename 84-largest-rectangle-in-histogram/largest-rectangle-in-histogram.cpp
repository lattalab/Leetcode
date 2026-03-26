class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        // edge case
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        int ans = 0;
        stack<int> st;
        st.push(0);
        // montonic increasing 
        for (int i=1; i<heights.size(); i++) {
            if (heights[i] >= heights[st.top()]) {
                st.push(i);
            }
            else {
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int h = heights[mid];
                        int w = i - st.top() - 1;
                        ans = max(ans, h*w);
                    }
                } 
                st.push(i);
            }
        }
        return ans;
    }
};