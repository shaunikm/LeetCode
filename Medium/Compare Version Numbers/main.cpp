/*
PROBLEM:
Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'.
Each revision consists of digits and may contain leading zeros.
Every revision contains at least one character. Revisions are 0-indexed from left to right,
with the leftmost revision being revision 0, the next revision being revision 1, and so on.
For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order.
Revisions are compared using their integer value ignoring any leading zeros.
This means that revisions 1 and 001 are considered equal. If a version number does not
specify a revision at an index, then treat the revision as 0. For example, version 1.0
is less than version 1.1 because their revision 0s are the same, but their revision 1s
are 0 and 1 respectively, and 0 < 1.

Return the following:
If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> split_s1; for (string s : split(version1)) split_s1.push_back(stoi(s));
        vector<int> split_s2; for (string s : split(version2)) split_s2.push_back(stoi(s));

        if (split_s1.size() > split_s2.size())
        {
            for (int i=0; i<split_s2.size(); i++)
            {
                if (split_s1[i] > split_s2[i]) { return 1; }
                else if (split_s1[i] < split_s2[i]) { return -1; }
            }

            for (int i=split_s2.size(); i<split_s1.size(); i++)
            {                
                if (split_s1[i] != 0) { return 1; }
            }

            return 0;
        }
        else if (split_s1.size() < split_s2.size())
        {
            for (int i=0; i<split_s1.size(); i++)
            {
                if (split_s1[i] > split_s2[i]) { return 1; }
                else if (split_s1[i] < split_s2[i]) { return -1; }
            }

            for (int i=split_s1.size(); i<split_s2.size(); i++)
            {
                if (split_s2[i] != 0) { return -1; }
            }

            return 0;
        } else {
            for (int i=0; i<split_s1.size(); i++)
            {
                if (split_s1[i] > split_s2[i]) { return 1; }
                else if (split_s1[i] < split_s2[i]) { return -1; }
            }
            return 0;
        }
    }

private:
    vector<string> split(string s)
    {
        vector<string> split_string;
        int start = 0; int end = s.find('.', start);

        while (end != -1)
        {
            split_string.push_back(s.substr(start, end - start));
            start = end + 1; end = s.find('.', start);
        }

        split_string.push_back(s.substr(start));

        return split_string;
    }
};

int main() {
    Solution sol = Solution();
    string version1 = "7.59.82";
    string version2 = "7.59.83";

    cout << sol.compareVersion(version1, version2) << endl;
}