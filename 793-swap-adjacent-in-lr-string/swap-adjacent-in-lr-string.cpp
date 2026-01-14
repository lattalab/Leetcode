class Solution {
public:
    bool canTransform(string start, string result) {
        int n = start.length();
        int i=0, j=0;

        while ( i < n || j < n ) {
            // skip X in both strings
            while (i < n && start[i] == 'X') i++;
            while (j < n && result[j] == 'X') j++;

            if (i == n && j == n) return true;
            // 一個已到盡頭，另一個沒有，則回傳否
            if (i==n || j==n) return false;

            // 可能超出邊界，所以要檢查
            if (i < n && j < n) {
                // point to the same index, should match
                if (start[i] != result[j]) return false;
                // move 'L' to left 
                if (start[i] == 'L' && i < j) return false;
                // move 'R' to right
                if (start[i] == 'R' && i > j) return false;
            
                // increment to move on next round
                i++; j++;
            }
        }
        return true;
    }
};