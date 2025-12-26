/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    // space complexity O(n)
    int *ans = (int*) malloc(sizeof(int) * numsSize);
    int index;
    *returnSize = numsSize;

    // 2 pointer
    int left=0, right=numsSize-1;
    for (index = numsSize-1; index >= 0; index--){
        int left_val = nums[left] * nums[left];
        int right_val = nums[right] * nums[right];
        
        if (left_val >= right_val){
            ans[index] = left_val;
            left++;
        }
        else {
            ans[index] = right_val;
            right--;
        }
    }
    return ans;
}