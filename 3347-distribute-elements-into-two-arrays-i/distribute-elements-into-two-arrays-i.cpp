class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> num1, num2;
        num1.push_back(nums[0]);
        num2.push_back(nums[1]);

        // iteractive compare num1 and num2, and add new element
        for (int i=2; i<nums.size(); i++) {
            if (num1.back() > num2.back()) {
                num1.push_back(nums[i]);
            }
            else {
                num2.push_back(nums[i]);
            }
        }

        // conta
        num1.insert(num1.end(), num2.begin(), num2.end());

        return num1;
    }
};