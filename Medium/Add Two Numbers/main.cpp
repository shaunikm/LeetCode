/**
 * PROBLEM:
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        int carryover = 0;
        ListNode* l1_traverser = l1;
        ListNode* l2_traverser = l2;

        /* create head node for linked list */
        ListNode* results = new ListNode();
        /* point to head node */
        ListNode* path = results;

        while (true)
        {
            /* set values if node doesn't exist */
            if (l1_traverser != nullptr) 
            {
                path->val += l1_traverser->val;
                /* point to next node */
                l1_traverser = l1_traverser->next;
            }
            
            if (l2_traverser != nullptr)
            {
                path->val += l2_traverser->val;
                /* point to next node */
                l2_traverser  = l2_traverser->next;
            }

            /* add values of both nodes and only add the units place */
            path->val += carryover;

            /* carry the tens digit to the next node */
            if (path->val >= 10) {
                path->val -= 10;
                carryover = 1;
            } else {
                carryover = 0;
            }

            if (l1_traverser != nullptr || l2_traverser != nullptr)
            {
                /* traverse to next node */
                path->next = new ListNode();
                path = path->next;
            } else break;
        }

        /* create new node if carry over still there */
        if (carryover >= 1)
        {
            path->next = new ListNode();
            path->next->val = carryover;
        }
        
        return results;    
    }
};

int main() {
    /* first linked list */
    ListNode l13 = ListNode();
    ListNode l12 = ListNode();
    ListNode l11 = ListNode();
    ListNode l1 = ListNode();

    ListNode* p12 = &l12;
    p12->val = 2;

    ListNode* p11 = &l11;
    p11->val = 3;
    p11->next = p12;

    ListNode* p1 = &l1;
    p1->val = 8;
    p1->next = p11;

    /* second linked list */
    ListNode l22 = ListNode();
    ListNode l21 = ListNode();
    ListNode l2 = ListNode();

    ListNode* p22 = &l22;
    p22->val = 1;

    ListNode* p21 = &l21;
    p21->val = 2;
    p21->next = p22;

    ListNode* p2 = &l2;
    p2->val = 9;
    p2->next = p21;

    Solution sol = Solution();

    ListNode* prod = sol.addTwoNumbers(p1, p2);
    ListNode* next_prod = prod->next;
    cout << prod->val << " -> ";
    while (next_prod != nullptr) {
        cout << next_prod->val << " -> ";
        next_prod = next_prod->next;
    }
    cout << "nullptr" << endl;
    delete prod;
    delete next_prod;
}