class Solution {
public:
    int gcd(int x, int y) {
        if (y==0) return x;
        else return gcd(y, x%y);
    }
    long long gcdSum(vector<int>& nums) {
        // iterate the nums, while maintaining the max and calculate prefixGcd
        int mx = nums[0];
        vector<int> prefixGcd;
        for (int i=0; i<nums.size(); i++) {
            mx = max(mx, nums[i]);
            int temp = gcd(nums[i], mx);
            prefixGcd.push_back(temp);
        }
        // sorting into non-decreasing
        sort(prefixGcd.begin(), prefixGcd.end());
        // pair gcd
        long long result = 0;
        int left = 0, right = prefixGcd.size() - 1;
        while (left < right) {
            result += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        return result;
    }
};