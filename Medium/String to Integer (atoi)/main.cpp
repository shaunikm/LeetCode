/*
PROBLEM:
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'.
Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result
is positive if neither is present. Read in next the characters until the next non-digit character or the end of the input
is reached. The rest of the string is ignored. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits
were read, then the integer is 0. Change the sign as necessary (from step 2). If the integer is out of the 32-bit signed integer
range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped
to -231, and integers greater than 231 - 1 should be clamped to 231 - 1. Return the integer as the final result.

NOTE:
Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool neg = false;
        bool sign = false;
        long parsed = 0;

        for (char c : s) {
            if (c >= 48 && c <= 57)
            {
                sign = true;
                parsed = 10*parsed + (int)c - 48;
                if (parsed > INT_MAX) {
                    if (neg) return INT_MIN;
                    else return INT_MAX;
                }
            }
            else if (c == '-' && !(sign))
            {
                neg = true;
                sign = true;
            }
            else if (c == '+' && !(sign)) { sign = true; }
            else if ((int)c != 32 && !(sign)) { return 0; }
            else if (((int)c < 48 || (int)c > 57) && sign) { break; }
        }

        if (neg) return parsed*-1;
        else return parsed;
    }
};

int main() {
    Solution sol = Solution();

    cout << sol.myAtoi("   +0 123") << endl;
}