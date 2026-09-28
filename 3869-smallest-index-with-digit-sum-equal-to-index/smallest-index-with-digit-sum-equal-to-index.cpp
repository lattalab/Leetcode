class Solution {
public:
    int DigitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            int temp = DigitSum(nums[i]);
            if (temp == i) {
                return i;
            }
        }
        return -1;
    }
};