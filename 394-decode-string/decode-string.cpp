class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        int num = 0;
        string curr;
        for (int i=0; i<s.size(); i++) {
            // calculate the repeat number
            if (isdigit(s[i])) {
                num = num*10 + (s[i] - '0');
            }
            else if (s[i] == '[') {
                countStack.push(num);
                num = 0;

                string temp = "";
                temp += s[i];
                stringStack.push(temp);
            }
            else if (s[i] == ']') {
                string temp = "";
                while (!stringStack.empty() && stringStack.top() != "[") {
                    temp = stringStack.top() + temp;
                    stringStack.pop();
                }
                stringStack.pop();  // remove "["

                int num = countStack.top();
                countStack.pop();

                // repeat n times;
                string temp_ans = "";
                while (num--) {
                    temp_ans += temp;
                }

                stringStack.push(temp_ans);
            }
            else {
                // push the single character
                string temp = "";
                temp += s[i];
                stringStack.push(temp);
            }
        }
        
        // restore to final answer
        string ans;
        while (!stringStack.empty()) {
            ans = stringStack.top() + ans;
            stringStack.pop();
        }

        return ans;
    }
};