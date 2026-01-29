class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while (right > left) {
            int temp = numbers[left] + numbers[right];
            if (temp > target) right--;
            else if (temp < target) left++;
            else {
                // assume exact one solution
                return {left+1, right+1};
            }
        }
        return {};
    }
};