int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    int ans = 0;
    int left = 0;
    int right = 0;
    int prod = 1;

    while (right < numsSize) {
        prod *= nums[right];
        while (prod >= k) {
            prod /= nums[left];
            left++;
        }
        // calculate all valid subarray ends with right
        ans += right - left + 1;
        right++;
    }

    return ans;
}