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
        bool longer = false;
        int remainder = 0;
        ListNode* next1;
        ListNode* next2;
        next1 = l1->next;
        next2  = l2->next;

        while (true)
        {
            /* exit if linked list too large */
            if (next1 == nullptr) {
                break;
            } else if (next2 == nullptr) {
                cout << "bigger" << endl;
                longer = true;
                break;
            }

            /* point to next */
            next1 = next1->next;
            next2  = next2->next;
            
        }

        if (longer) return l2;
        else return l1;
    }
};

int main() {
    /* first linked list */
    ListNode l13 = ListNode();
    ListNode l12 = ListNode();
    ListNode l11 = ListNode();
    ListNode l1 = ListNode();

    ListNode* p13 = &l13;
    p13->val = 5;

    ListNode* p12 = &l12;
    p12->val = 3;
    p12->next = p13;

    ListNode* p11 = &l11;
    p11->val = 4;
    p11->next = p12;

    ListNode* p1 = &l1;
    p1->val = 2;
    p1->next = p11;

    /* second linked list */
    ListNode l22 = ListNode();
    ListNode l21 = ListNode();
    ListNode l2 = ListNode();

    ListNode* p22 = &l22;
    p22->val = 4;

    ListNode* p21 = &l21;
    p21->val = 6;
    p21->next = p12;

    ListNode* p2 = &l2;
    p2->val = 5;
    p2->next = p21;

    Solution sol = Solution();

    ListNode* prod = sol.addTwoNumbers(p1, p2);
    ListNode* next_prod = prod->next;
    cout << prod->val << ' ';
    while (next_prod != nullptr) {
        cout << next_prod->val << ' ';
        next_prod = next_prod->next;
    }
    cout << endl;
}