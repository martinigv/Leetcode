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
    void reorderList(ListNode* head) {
        if (!head->next || !head->next->next) {
            return;
        }
        ListNode* h = head;
        ListNode* t = head;

        while (t->next->next)
            t = t->next;

        t->next->next = h->next;
        ListNode* temp = t->next->next;
        h->next = t->next;
        t->next = nullptr;

        reorderList(temp);
        return;
    }
};