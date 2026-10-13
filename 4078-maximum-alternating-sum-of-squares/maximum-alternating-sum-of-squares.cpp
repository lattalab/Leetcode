class Solution {
public:
    struct cmp {
        bool operator() (const int &a, const int &b) {
            return a*a < b*b;
        }
    };
    long long maxAlternatingSum(vector<int>& nums) {
        // sorted by square number from small to large
        sort(nums.begin(), nums.end(), cmp());
        int n = nums.size();
        long long int sum = 0;
        // put smaller in odd index
        for (int i=0; i<n/2; i++) {
            sum -= (nums[i] * nums[i]);
        }
        // put larger in even index
        for (int j=n/2; j<n; j++) {
            sum += (nums[j] * nums[j]);
        }
        return sum;
    }
};