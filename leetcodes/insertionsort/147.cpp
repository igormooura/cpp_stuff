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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* start = new ListNode(0); 
        start->next = head;
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->next->val < curr->val) {
                ListNode *prev = start;

                while(prev->next && prev->next->val < curr->next->val) {
                    prev = prev->next;
                }

                ListNode *temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;
            } else {
                curr = curr->next;
            }
        }

        return start->next;
    }
};

// ========================== AI GENERATED =========================================
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 2, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode* head = createList(arr, n);

    cout << "Lista original: ";
    printList(head);

    Solution sol;
    ListNode* sorted = sol.insertionSortList(head);

    cout << "Lista ordenada: ";
    printList(sorted);

    return 0;
}
