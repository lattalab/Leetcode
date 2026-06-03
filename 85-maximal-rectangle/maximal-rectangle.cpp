class Solution {
public:
    int largestArea(vector<int> heights) {
        int result = 0;
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        st.push(0);
        for (int i=1; i<heights.size(); i++) {
            if (heights[i] > heights[st.top()]) {
                st.push(i);
            }
            else if (heights[i] == heights[st.top()]) {
                st.push(i);
            }
            else {
                while (!st.empty() && heights[i] < heights[st.top()]) {
                   int mid = st.top();
                   st.pop();
                   if (!st.empty()) {
                    int left = st.top();
                    int right = i;
                    int w = right - left - 1;
                    int h = heights[mid];
                    result = max(result, h*w);
                   } 
                }
                st.push(i);
            }
        }
        return result;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        // translate to maximum height in each column
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] == '1')
                    heights[j] ++;
                else
                    heights[j] = 0;
            }
            ans = max(ans, largestArea(heights));
        }
        return ans;
    }
};