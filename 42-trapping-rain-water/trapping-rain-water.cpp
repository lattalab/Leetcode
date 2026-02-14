class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left =0, right = height.size() - 1;
        int maxLeft= height[left], maxRight = height[right];
        while (left < right) {
            if (height[left] < height[right]) {
                left++;
                maxLeft = max(maxLeft, height[left]);
                ans += (maxLeft - height[left]);
            }
            else {
                right--;
                maxRight = max(maxRight, height[right]);
                ans += (maxRight - height[right]);
            }
        }
        return ans;
    }
};