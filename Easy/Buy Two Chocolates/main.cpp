#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        if (money - (prices[0] + prices[1]) >= 0) {
            return money - (prices[0] + prices[1]);
        } else {
            return money;
        }
    }
};

int main() 
{
    Solution sol;
    vector<int> prices = {2, 1, 2};

    cout << sol.buyChoco(prices, 3) << endl;
} 