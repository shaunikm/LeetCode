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
        
        for (int i=0; i < g_size; i++)
        {
            try
            {
                if (nums1[0] < nums2[0]) {
                    group.push_back(nums1[0]);
                    nums1.erase(nums1.begin());
                } else {
                    group.push_back(nums2[0]);
                    nums2.erase(nums2.begin());
                }
            } catch (exception &e)
            {
                group.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
        }
        cout << g_size << endl;

        for (auto i : group) {
            cout << i << endl;
        }
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {1, 2, 2};

    sol.findMedianSortedArrays(nums1, nums2);
}