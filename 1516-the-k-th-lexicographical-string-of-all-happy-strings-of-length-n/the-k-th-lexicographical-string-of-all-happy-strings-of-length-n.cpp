class Solution {
public:
    string backtracking(string &result, int n, int &k) {
        if (result.size() == n) {
            // fuillful necessary length
            k--;
            if (k == 0) return result;
            // otherwise remove the element, and start next round
            return "";
        }
        
        // increasing add element
        for (char ch='a'; ch<='c'; ch++) {
            if (result.size() > 0 && result.back() == ch) {
                // dis-satisify happy string
                continue;
            }
            result.push_back(ch);
            string temp = backtracking(result, n, k);
            // check if previous result is valid or not
            // if valid, then directly return
            if (temp != "") return result;
            result.pop_back();
        }
        // after tracing all case
        return "";
    }
    string getHappyString(int n, int k) {
        string ans = "";
        ans = backtracking(ans, n, k);
        return ans;
    }
};