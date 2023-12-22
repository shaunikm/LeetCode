/*
PROBLEM:
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> group;
        int g_size = nums1.size() + nums2.size();

        if (nums2.size() <= 0)
            if (nums1.size() % 2)
                return nums1[(int)(nums1.size()/2)];
            else
                return (nums1[(int)(nums1.size()/2) - 1] + nums1[(int)(nums1.size()/2)])/2.0;
            
        else if (nums1.size() <= 0)
            if (nums2.size() % 2)
                return nums2[(int)(nums2.size()/2)];
            else
                return (nums2[(int)(nums2.size()/2) - 1] + nums2[(int)(nums2.size()/2)])/2.0;
        
        for (int i=0; i < g_size; i++)
        {
            if ((nums1[0] < nums2[0] && nums1.size() > 0) || nums2.size() <= 0)
            {
                group.push_back(nums1[0]); nums1.erase(nums1.begin());
            }
            else
            {
                group.push_back(nums2[0]); nums2.erase(nums2.begin());
            }
        }

        if (group.size() % 2)
            return group[(int)(group.size()/2)];
        else
            return (group[(int)(group.size()/2) - 1] + group[(int)(group.size()/2)])/2.0;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
}