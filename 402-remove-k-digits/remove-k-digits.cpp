class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        st.push(num[0]);
        for (int i=1; i<num.size(); i++) {
            char s = num[i];
            if (s > st.top()) {
                st.push(s);
            }
            else if (s == st.top()) {
                st.push(s);
            }
            else {
                while (!st.empty() && s < st.top() && k) {
                    st.pop();
                    k--;
                }
                st.push(s);
            }
        } 

        // post processing: if there can still remove more characters:
        if (k > 0) {
            while (!st.empty() && k) {
                st.pop();
                k--;
            }
        }

        // convert to num
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        // reverse the string to get correct sequence
        reverse(ans.begin(), ans.end());
        // remove leading 0s
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i);

        return (ans.length() == 0) ? "0" : ans;
    }
};