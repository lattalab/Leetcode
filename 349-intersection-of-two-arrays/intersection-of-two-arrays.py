class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # find element in nums1
        hash = {}
        for num in nums1:
            hash[num] = hash.get(num, 0) + 1

        # see if elements in nums2, exist in nums1 too
        res = set()
        for num in nums2:
            if num in hash:
                res.add(num)
                del hash[num]

        return list(res)