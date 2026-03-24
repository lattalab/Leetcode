int trap(int* height, int heightSize) {
    int left = 0, right = heightSize -1;
    int maxLeft = height[left], maxRight = height[right];
    int ans = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            left++;
            maxLeft = (height[left] > maxLeft) ? height[left] : maxLeft;    
            ans += (maxLeft - height[left]);
        }
        else {
            right--;
            maxRight = (height[right] > maxRight) ? height[right] : maxRight;    
            ans += (maxRight - height[right]);
        }
    }
    return ans;
}