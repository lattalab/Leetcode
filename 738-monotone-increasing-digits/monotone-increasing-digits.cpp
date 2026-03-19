class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string number = to_string(n);
        int flag = number.size();
        // 從後面像前面遍歷，可以利用之前處理的結果
        for (int i=number.size()-1; i>0; i--) {
            if (number[i-1] > number[i]) {
                number[i-1]--;
                flag = i;
            }
        }
        // 將後面全變為9
        for (int i=flag; i<number.size(); i++) {
            number[i] = '9';
        }
        return stoi(number);
    }
};