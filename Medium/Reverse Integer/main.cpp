/*
PROBLEM:
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/
#include <iostream>
using namespace std;

#include <cmath>

class Solution {
public:
    int reverse(int x) {
        if (x > INT_MAX || x <= INT_MIN)
            return 0;
        int reversed = 0;
        long addend;
        bool neg;

        if (x < 0) {
            neg = true;
            x *= -1;
        }
        else {
            neg = false;
        }

        for (int i=0; i<floor(log10(x) + 1); i++) {
            addend = (int)(x / pow(10, i)) % 10 * pow(10, floor(log10(x) + 1)-i-1);
            if (addend + reversed < INT_MIN || addend + reversed > INT_MAX)
                return 0;
            reversed += addend;
        }

        if (neg)
            return reversed * -1;
        else
            return reversed;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.reverse(-2147483648) << endl;
}