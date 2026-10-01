class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char left[3] = {'(', '[', '{'};
        char right[3] = {')', ']', '}'};
        for (int i=0; i<s.size(); i++) {
            // find if there is left para
            for (int j=0; j<3; j++) {
                if (s[i] == left[j]) {
                    st.push(s[i]);
                }
            }
            // check if it can pop
            for (int j=0; j<3; j++) {
                if (s[i] == right[j]) {
                    if (!st.empty() && st.top() == left[j]) {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        return st.size() == 0;
    }
};