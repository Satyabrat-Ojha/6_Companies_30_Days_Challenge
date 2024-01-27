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
    struct compare {
        bool operator()(const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(auto list:lists) {
            if(list != NULL) {
                pq.push({list});
            }
        }

        if(pq.empty()) return NULL;
        auto ans = new ListNode(pq.top()->val);
        auto tail = ans;
        if(pq.top()->next != NULL)
            pq.push(pq.top()->next);
        pq.pop();

        while(!pq.empty()) {
            auto temp = new ListNode(pq.top()->val);
            tail->next = temp;
            tail = temp;
            if(pq.top()->next != NULL)
                pq.push(pq.top()->next);
            pq.pop();
        }

        return ans;
    }
};