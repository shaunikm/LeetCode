"""
PROBLEM:
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
"""
from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        group = []
        for i in range(len(nums1) + len(nums2)):
            try:
                try:
                    if nums1[0] < nums2[0]:
                        group.append(nums1[0])
                        del nums1[0]
                    else:
                        group.append(nums2[0])
                        del nums2[0]
                except IndexError:
                    group.append(nums1[0])
                    del nums1[0]
            except IndexError:
                group.append(nums2[0])
                del nums2[0]
        if len(group) % 2:
            return group[len(group)//2]
        else:
            return (group[len(group)//2 - 1] + group[len(group)//2])/2


if __name__ == "__main__":
    sol = Solution()
    print(sol.findMedianSortedArrays([1,2], [3, 5]))