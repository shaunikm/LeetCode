from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        print(l1.val)
        print(l1.next.val)

if __name__ == "__main__":
    # definition of first Linked List
    l12 = ListNode(3)
    l11 = ListNode(4, l12)
    l1 = ListNode(2, l11)
    
    # definition of second Linked List
    l22 = ListNode(4)
    l21 = ListNode(6, l22)
    l2 = ListNode(5, l21)
    
    # solution
    sol = Solution()
    print(sol.addTwoNumbers(l1, l2))