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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        set<pair<int,ListNode*>> s;
        auto head = new ListNode(0);
        auto tail = head;

        for(auto list:lists)
            if(list) s.insert({list->val, list});

        while(!s.empty()) {
            auto node = (*s.begin()).second;
            s.erase(s.begin());

            if(node->next) s.insert({node->next->val, node->next});

            tail->next = node;
            tail = tail->next;
        }

        return head->next;
    }
};