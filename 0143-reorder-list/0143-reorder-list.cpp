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
        // in 1->2->3->4->5->6 find 4
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // convert 1->2->3->4->5->6 into 1->2->3->4 and 6->5->4
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* temp;
        while (curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        // merge 1->2->3->4 and 6->5->4 into 1->6->2->5->3->4
        ListNode* first = head;
        ListNode* second = prev;
        while (second->next) {
            temp = first->next;
            first->next = second;
            first = temp;
            temp = second->next;
            second->next = first;
            second = temp;
        }
    }
};