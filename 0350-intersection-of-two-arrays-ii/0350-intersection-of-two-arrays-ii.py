class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        inter = set(nums1) & set(nums2)
        res = []
        for n in inter:
            res.extend([n] * nums1.count(n) if nums1.count(n) <= nums2.count(n) else [n] * nums2.count(n))
        return res    