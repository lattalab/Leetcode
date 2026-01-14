class Solution {
public:
    vector<string> result;
    string path;
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
    void backtracking(string &digits, int startIndex) {
        if (path.size() == digits.size()) {
            result.push_back(path);
            return;
        }

        // convert string 'digit' to int 
        int digit = digits[startIndex] - '0';
        // map to desired set
        string letters = letterMap[digit]; 
        for (int i=0; i<letters.size(); i++) {
            path.push_back(letters[i]);
            backtracking(digits, startIndex + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        path.clear();
        result.clear();
        backtracking(digits, 0);
        return result;
    }
};