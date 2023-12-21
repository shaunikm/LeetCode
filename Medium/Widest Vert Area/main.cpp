/*
PROBLEM:
Given n points on a 2D plane where points[i] = [xi, yi],
Return the widest vertical area between two points such that no points are inside the area.

A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height).
The widest vertical area is the one with the maximum width.

Note that points on the edge of a vertical area are not considered included in the area.
*/

#include <iostream>
#include <vector>
using namespace std;

#include <algorithm>

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int difference = 0;
        int temp;

        auto compare = [](const vector<int>& v1, const vector<int>& v2)->bool {return v1[0] < v2[0];};
        sort(points.begin(), points.end(), compare);

        for (int i=1; i<points.size(); i++)
        {
            temp = points[i][0]-points[i-1][0];
            if (difference < temp)
                difference = temp;
        }
        
        return difference;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> points {{3,1},{9,0},{1,0},{1,4},{5,3},{8,8}};

    cout << sol.maxWidthOfVerticalArea(points) << endl;
}