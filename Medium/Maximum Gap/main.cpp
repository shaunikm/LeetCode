/*
PROBLEM:
Given an integer array nums, return the maximum difference between two successive elements
in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.
*/
#include <iostream>
#include <vector>
using namespace std;

#include <algorithm>

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int maxDist = 0;

        for (int i=0;i<nums.size()-1;i++)
        {
            if (nums.at(i+1) - nums.at(i) > maxDist)
                maxDist = nums.at(i+1) - nums.at(i);
        }

        return maxDist;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {3,6,9,1};

    cout << sol.maximumGap(nums) << endl;
}