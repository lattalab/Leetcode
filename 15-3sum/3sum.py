class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort() # ascending order
        for idx, n in enumerate(nums):

            # remove repetive
            # Because previous all possible solution have been check
            if idx > 0 and nums[idx] == nums[idx-1]:
                continue

            left = idx + 1
            right = len(nums) - 1

            while left < right:
                three_sum = n + nums[left] + nums[right]

                if three_sum > 0:
                    right -= 1
                elif three_sum < 0:
                    left += 1
                else:
                    res.append([nums[idx], nums[left], nums[right]])
                
                    # remove repetive for left and right
                    while (right > left and nums[left] == nums[left+1]):
                        left += 1
                    while (right > left and nums[right] == nums[right-1]):
                        right -= 1

                    # update pointer
                    left += 1
                    right -= 1
            
        return res
            