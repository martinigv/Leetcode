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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
            return nullptr;
        vector<ListNode*> v{}; // store lists value with index;
        bool iscycle = false;
        while(1) {
            if (auto index = find(v.begin(), v.end(), head) != v.end()) {
                iscycle = true;
                break;
            }
            if (!head) {
                break;
            }
            v.push_back(head);
            head = head->next;

        }
        if (iscycle) {
            return head;
        }
        else {
            return nullptr;
        }
    }
};