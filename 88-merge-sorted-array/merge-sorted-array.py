class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        start = m
        for i in nums2:
            nums1[start] = i
            start +=1
        nums1.sort()