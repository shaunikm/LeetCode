"""
PROBLEM:
Given n points on a 2D plane where points[i] = [xi, yi],
Return the widest vertical area between two points such that no points are inside the area.

A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height).
The widest vertical area is the one with the maximum width.

Note that points on the edge of a vertical area are not considered included in the area.
"""

from typing import List

class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        difference = 0
        points.sort(key=lambda x: x[0])
        
        for i in range(1, len(points)):
            difference = max(difference, points[i][0]-points[i-1][0])
        
        return difference

if __name__ == "__main__":
    sol = Solution()
    points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
    
    print(sol.maxWidthOfVerticalArea(points))