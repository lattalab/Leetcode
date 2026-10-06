class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        stack<char> st;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            }
            else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    ans++;
                }
            }
        }
        
        if (!st.empty()) ans += st.size();
        return ans;
    }
};