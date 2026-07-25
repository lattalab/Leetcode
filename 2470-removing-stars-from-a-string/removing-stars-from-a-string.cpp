class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '*') {
                if (!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(s[i]);
            }
        }

        // revert to string
        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};