class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> digit;
        queue<int> q;
        // push 1~9
        for (int i=1; i<=9; i++) q.push(i);
        // expand by bfs
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                int x = q.front();
                q.pop();
                digit.push_back(x);
                int d = x % 10;
                if (d < 9) {
                    int s = x*10 + (d + 1);
                    q.push(s);
                }
            }
        }

        // finding the range
        vector<int> ans;
        for (auto num : digit) {
            if (low <= num && num <= high) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};