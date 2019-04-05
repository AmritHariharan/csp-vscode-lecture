#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode * lead = new ListNode(0);
    ListNode * follow = lead;
    lead->next = head;
    
    // We're given that n will always be valid
    for (int i = 0; i < n; ++i) {
        lead = lead->next;
    }
    
    while (lead->next) {
        lead = lead->next;
        follow = follow->next;
    }
    
    ListNode * temp = follow->next;
    if (head == temp) head = head->next;
    follow->next = follow->next->next;
    delete temp;

    return head;
}

int main(int argc, char const *argv[]) {
    ListNode* n1 = new ListNode(5);
    ListNode* n2 = new ListNode(34);
    ListNode* n3 = new ListNode(19);
    ListNode* n4 = new ListNode(99);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // List with head @ n1:
    // 5 -> 34 -> 19 -> 99

    // Remove 19
    ListNode* h = removeNthFromEnd(n1, atoi(argv[1]));

    while (h) {
        cout << h->val << " ";
        h = h->next;
    }
    cout << endl;

    return 0;
}
