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
        int temp = 0;
        int skip[colors.size()];

        for (int i = 1; i < colors.length(); i++)
        {
            if (colors[i] == colors[i-1]) {
                if (skip[i-1] == 1) {
                    temp = i-1;
                    while (true) {
                        if (skip[temp] == 1) {
                            temp--;
                        } else break;
                    }
                    if (neededTime[i] > neededTime[temp]) {
                        cost += neededTime[temp];
                        skip[temp] = 1;
                    } else {
                        cost += neededTime[i];
                        skip[i] = 1;
                    }
                }
                else if (neededTime[i] > neededTime[i-1]) {
                    cost += neededTime[i-1];
                    skip[i-1] = 1;
                } else {
                    cost += neededTime[i];
                    skip[i] = 1;
                }
            }
        }

        return cost;
    }
};

/*
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;

        for (int i = 1; i < colors.length(); i++)
        {
            if (colors[i] == colors[i-1]) {
                if (neededTime[i] > neededTime[i-1]) {
                    cost += neededTime[i-1];
                    colors.erase(i-1, 1);
                    neededTime.erase(neededTime.begin()+i-1, neededTime.begin()+i);
                    i--;
                } else {
                    cost += neededTime[i];
                    colors.erase(i, 1);
                    neededTime.erase(neededTime.begin()+i, neededTime.begin()+i+1);
                    i--;
                }
            }
        }

        return cost;
    }
};
*/

int main() {
    Solution sol = Solution();
    string colors = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<int> neededTime = {2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,2,1,2,4,1,};

    cout << sol.minCost(colors, neededTime) << endl;
}