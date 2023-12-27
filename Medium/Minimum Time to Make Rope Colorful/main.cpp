/**
 * PROBLEM:
 * Alice has n balloons arranged on a rope.
 * You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
 * Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, 
 * so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given 
 * a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove
 * the ith balloon from the rope. Return the minimum time Bob needs to make the rope colorful.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        // char temp = NULL;

        for (int i = 1; i < colors.length(); i++)
        {
            if (colors[i] == colors[i-1]) {
                if (neededTime[i] > neededTime[i-1]) {
                    cost += neededTime[i-1];
                } else {
                    cost += neededTime[i];
                }
            }
        }

        return cost;
    }
};

int main() {
    Solution sol = Solution();
    string colors = "aaaaa";
    vector<int> neededTime = {1,2,3,4,1};

    cout << sol.minCost(colors, neededTime) << endl;
}