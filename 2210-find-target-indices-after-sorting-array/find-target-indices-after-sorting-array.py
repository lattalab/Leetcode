class Solution(object):
    def targetIndices(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        less = 0; equal = 0
        for n in nums:
            if n < target:
                less += 1
            elif n == target:
                equal += 1
        
        ans = [i for i in range(less, less+equal)]
        return ans