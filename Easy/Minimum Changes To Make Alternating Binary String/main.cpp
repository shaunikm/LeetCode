/**
 * PROBLEM:
 * You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1'
 * or vice versa. The string is called alternating if no two adjacent characters are equal. For example, the string "010"
 * is alternating, while the string "0100" is not. Return the minimum number of operations needed to make s alternating.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        char fs  = s[0];
        char sec; if (fs == '1') sec = '0'; else sec = '1';
        int prev_changes = 0;
        int end_changes = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (i % 2 && s[i] != sec) prev_changes++;
            else if (!(i % 2) && s[i] != fs) prev_changes++;
            if (i % 2 && s[i] != fs) end_changes++;
            else if (!(i % 2) && s[i] != sec) end_changes++;
        }

        if (prev_changes > end_changes) return end_changes;
        else return prev_changes;
    }
};

int main() {
    Solution sol = Solution();

    sol.minOperations("0100");
}