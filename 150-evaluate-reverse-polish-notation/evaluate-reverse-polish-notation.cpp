class Solution {
public:
    // test case contain "long long" test case

    long long StringToInt (string s){
        long long num =0;
        int neg = 0;
        for (int i=0; i<s.size(); i++){

            if (s[i] == '-'){
                neg = 1;
                continue;
            }

            num *= 10;
            num += (s[i] - '0');
        }
        return (neg) ? -num : num;
    }

    string IntToString (long long num){
        
        long long number = abs(num);
        string res = "";
        while (number) {
            int digit = number % 10;
            res += (char) (digit + '0');
            number /= 10;
        }
        reverse(res.begin(), res.end());
        return (num >= 0) ? res : "-" + res;
    }

    int evalRPN(vector<string>& tokens) {
       stack<string> st;
       for (int i=0; i<tokens.size(); i++){
            if (tokens[i] == "+"){
                long long num1 = StringToInt(st.top()); st.pop();
                long long num2 = StringToInt(st.top()); st.pop();
                string res = IntToString(num2 + num1);
                st.push(res);
            } else if (tokens[i] == "-"){
                long long num1 = StringToInt(st.top()); st.pop();
                long long num2 = StringToInt(st.top()); st.pop();
                string res = IntToString(num2 - num1);
                st.push(res);
            } else if (tokens[i] == "*"){
                long long num1 = StringToInt(st.top()); st.pop();
                long long num2 = StringToInt(st.top()); st.pop();
                string res = IntToString(num2 * num1);
                st.push(res);
            } else if (tokens[i] == "/"){
                long long num1 = StringToInt(st.top()); st.pop();
                long long num2 = StringToInt(st.top()); st.pop();
                string res = IntToString(num2 / num1);
                st.push(res);
            } else {
                st.push(tokens[i]);
            }
       } 

        long long ans = StringToInt(st.top()); 
        return ans;
    }
};