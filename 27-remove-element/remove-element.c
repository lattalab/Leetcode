int removeElement(int* nums, int numsSize, int val) {
    int len = numsSize;
    int left = 0, expected = 0;   // 2 pointers
    for (left=0; left < len; left++){
        if (nums[left] != val){
            nums[expected++] = nums[left];
        }
    }
    return expected;
}