/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = size(head);
        n = sz - n;
        if(n == 0) return head->next;
        remove(n, head);
        return head;
    }

    void remove(int n, ListNode* head) {
        while(n > 1) { head = head->next; n--; }
        head->next = head->next->next;
    }

    int size(ListNode* head) {
        int res = 1;
        while(head->next) {
            res++;
            head = head->next;
        }
        return res;
    }
};