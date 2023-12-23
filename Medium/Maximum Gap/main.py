"""
PROBLEM:
Given an integer array nums, return the maximum difference between two successive elements
in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.
"""
from typing import List

class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        if len(nums) < 2: return 0
        maxDist = 0
        nums = sorted(nums)
        for i in range(len(nums)-1):
            maxDist = max(maxDist, nums[i+1]-nums[i])
        return maxDist

if __name__ == "__main__":
    sol = Solution()
    print(sol.maximumGap([3,6,9,1]))