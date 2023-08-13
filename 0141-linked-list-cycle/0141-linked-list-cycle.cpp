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
        bool iscycle = false;

        if (!head)
            return iscycle;
        vector<ListNode*> v{};

        while(1) {
            if (find(v.begin(), v.end(), head) != v.end())
                return iscycle = true;
            if(!head)
                return iscycle;
            v.push_back(head);
            head = head->next;
        }
        return iscycle;

    }
};