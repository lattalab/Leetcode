class Solution {
public:
    void reverse(string &s){
        // 2 pointer
        int start = 0;
        int end = s.size() -1;
        while (start < end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string removeDuplicates(string s) {
        stack<char> st;
        for (int i=0; i<s.size(); i++){

            if (st.empty() || st.top() != s[i])
                st.push(s[i]);
            else {
                st.pop();
            }
        }

        // fetch character
        string result = "";
        while (!st.empty()){
            result += st.top();
            st.pop();
        }

        reverse(result);
        return result;
    }
};