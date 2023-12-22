"""
PROBLEM:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Follow-up: Can you come up with an algorithm that is less than O(n^2) time complexity?
"""

from typing import List

class Solution:
    def twoSum(nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            remainder = target-nums[i]
            try:
                return [i, nums[i+1:].index(remainder) + i + 1]
            except:
                pass
            
if __name__ == "__main__":
    sol = Solution()
    nums = [3,2,4]
    target = 6
    
    print(Solution.twoSum(nums, target))