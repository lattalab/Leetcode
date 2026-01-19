class Solution {
public:
    bool canChange(string start, string target) {
        int length = start.length();
        int i=0, j=0;

        for (i=0, j=0; i<length; i++) {
            if (start[i] == '_') continue;
            // 現在 start 卡在 'L' or 'R'

            // 之後 while 將 target 移動到 'L' or 'R'
            // 注意要限制在長度範圍，不然會 index out of bound
            while(j<length && target[j] == '_') {
                j++;
                continue;
            }

            cout << i << " " << j << endl;

            // 不能移動的時候
            if (start[i] != target[j]) return false;
            if ((start[i] == 'L') && (j > i || j == length)) return false;
            if ((start[i] == 'R') && (i > j || j == length)) return false;

            // 可以移動則改變 j 的 位置 (才能跑下一次)
            j++;
        }

        // 以上保證 start 會遍歷完成
        // 還需要檢查 target，有可能還有遍歷完
        // 這時不應該出現任何 'L' or 'R'，因 start 沒有多餘的元素
        // 例如: start = L_LR, target = LL_RR
        for (j; j<length; j++) {
            if (target[j] != '_') return false;
        }

        return true;
    }
};