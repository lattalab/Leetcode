class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        pair_sum = {}   # store occurance time for such pair
        for n1 in nums1:
            for n2 in nums2:
                if n1 + n2 in pair_sum:
                    pair_sum[n1+n2] += 1
                else:
                    pair_sum[n1+n2] = 1

        count = 0
        for n3 in nums3:
            for n4 in nums4:
                target = 0 - (n3 + n4)
                if target in pair_sum:
                    count += pair_sum[target]

        return count