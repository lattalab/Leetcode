int minSubArrayLen(int target, int* nums, int numsSize) {
    int start=0, end=0;
    int ans = INT_MAX;
    int sum = 0;

    for (int end = 0; end < numsSize; end++) {
        sum += nums[end];

        // shrink window while sum is big enough
        while (sum >= target) {
            int subLength = (end - start + 1);
            ans = ans <  subLength ? ans : (end - start + 1);
            sum -= nums[start++];
        }
    }
    return ans == INT_MAX ? 0 : ans;
}