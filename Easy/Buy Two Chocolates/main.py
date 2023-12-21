from typing import List

class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        if money - sum(sorted(prices)[:2]) >= 0: return money - sum(sorted(prices)[:2])
        else: return money

if __name__ == "__main__":
    sol = Solution()
    prices = [3,2,3]
    money = 3
    
    print(sol.buyChoco(prices, money))