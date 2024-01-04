/**
 * PROBLEM:
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    if (head == nullptr) cout << "nullptr" << endl;
    else {
        ListNode* hn = head->next;
        cout << head->val << " -> ";
        while (hn != nullptr) {
            cout << hn->val << " -> ";
            hn = hn->next;
        }
        cout << "nullptr" << endl;
    }
}

ListNode* createList(vector<int>& ls) {
    vector<ListNode*> linkedls(ls.size());

    for (int i = 0; i < ls.size(); i++) {
        linkedls[i] = new ListNode(ls[i]);
    }

    for (int i = 0; i < ls.size()-1; i++) {
        linkedls[i]->next = linkedls[i+1];
    }

    return linkedls[0];
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* Initialize vector of nodes and path to traverse list */
        vector<ListNode*> nodes = {};
        ListNode* path = head;

        /* Add all nodes to vector */
        while (path != nullptr) {
            nodes.push_back(path);
            path = path->next;
        }

        /* Free memory allocated for nth node */
        // delete nodes[nodes.size()-n];
        nodes.erase(nodes.begin()+nodes.size()-n, nodes.begin()+nodes.size()-n+1);

        /* Return new head node and change pointers to skip freed node */
        if (n == 1) { nodes[nodes.size()-n]->next = nullptr; return nodes[0]; }
        else if (nodes.size() > 1) nodes[nodes.size()-n]->next = nodes[nodes.size()-n+1];
        else if (nodes.size() < 1) return nullptr;

        return nodes[0];
    }
};

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         /* Initialize vector of nodes and path to traverse list */
//         vector<ListNode*> nodes = {};
//         ListNode* path = head;

//         /* Add all nodes to vector */
//         while (path != nullptr) {
//             nodes.push_back(path);
//             path = path->next;
//         }

//         /* Free memory allocated for nth node */
//         delete nodes[nodes.size()-n];

//         /* Return new head node and change pointers to skip freed node */
//         if (nodes.size() == n) return nodes[1];
//         else if (nodes.size() > 1) nodes[nodes.size()-n-1]->next = nodes[nodes.size()-n+1];
//         else if (nodes.size() == 1) return nullptr;

//         return nodes[0];
//     }
// };

int main() {
    /* Creating Linked List */
    vector<int> vals = {1,2,3};
    ListNode* head = createList(vals);

    /* Outputting Linked List before changes */
    printList(head);

    /* Deleting nth element */
    Solution sol = Solution();
    head = sol.removeNthFromEnd(head, 1);

    /* Outputting Linked List after changes*/
    printList(head);

    /* Free memory used */
    delete head;
}