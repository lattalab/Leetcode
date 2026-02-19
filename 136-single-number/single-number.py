class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # sorting will make adjacent elements be similar
        nums.sort()
        for i in range(0, len(nums)-1, 2):
            if nums[i] != nums[i+1]:
                return nums[i]
        # boundary didn't examine after for-loop
        return nums[-1]