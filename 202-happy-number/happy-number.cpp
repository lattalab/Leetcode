class Solution {
public:
    int getSum (int n){
        int sum = 0;
        while(n){
            int digit = n%10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int num = n;
        set<int> st;
        while(1){
            num = getSum(num);
            if (num == 1) return true;
            
            // At first, set is empty.
            // then, find() can reach st.end()
            if (st.find(num) != st.end())
                return false;
            else
                st.insert(num);
        }
    }
};
