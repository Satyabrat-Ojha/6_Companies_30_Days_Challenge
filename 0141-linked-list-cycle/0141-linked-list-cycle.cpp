/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return 0;
        auto n1 = head, n2 = head->next;
        while(n1 != n2) {
            n1 = n1->next;
            if(!n2->next || !n2->next->next) return 0;
            n2 = n2->next->next;
        }
        return 1;
    }
};