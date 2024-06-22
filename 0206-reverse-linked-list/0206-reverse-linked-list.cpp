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
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        auto nxt = head->next;
        head->next = NULL;
        return rev(head, nxt);
    }

    ListNode* rev(ListNode* prv, ListNode* cur) {
        auto nxt = cur->next;
        cur->next = prv;
        if(nxt) return rev(cur, nxt);
        else return cur;
    }
};