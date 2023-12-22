/*
PROBLEM:
Given a string s, find the length of the longest 
substring without repeating characters.
*/

#include <iostream>
using namespace std;

// use a substring to check if past characters have been "seen"
// while iterating through the string
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int true_length = 0;
        int temp_length = 0;
        string seen;

        for (char c : s) {
            if (seen.find(c) == string::npos)
            {
                temp_length ++; seen.push_back(c);
            }
            else
            {
                if (temp_length > true_length)
                    true_length = temp_length;
                seen = seen.substr(seen.find(c)+1); seen.push_back(c); temp_length = seen.size();
            }
        }

        if (temp_length > true_length)
                true_length = temp_length;

        return true_length;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.lengthOfLongestSubstring("hwiufhewufhwehfekwfesbhvdsbk") << endl;
}