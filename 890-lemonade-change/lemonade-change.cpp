class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten  = 0;
        for (int i=0; i<bills.size(); i++) {
            if (bills[i] == 5) {
                // no change coin
                five++;
            }
            else if (bills[i] == 10) {
                // change coin with 5 dollar
                if (five <= 0) return false;
                five--;
                ten++;
            }
            else {
                // bills[i] == 20
                // 1. one ten dollar + one five dollar
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                // 2. with three five dollars
                else if (five >= 3) {
                    five -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};