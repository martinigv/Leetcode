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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        vector<int> v{};
        vector<int> v1 {};
        vector<int> v2 {};
        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        for (int i = 0; i < v.size(); i++) {
            if (v[i] < x) {
                v1.push_back(v[i]);
            }
            if (v[i] >= x) {
                v2.push_back(v[i]);
            }
        }
        v1.insert(v1.end(), v2.begin(), v2.end());

        temp = head;
        for (int i = 0; i < v1.size(); i++) {
            temp->val = v1[i];
            temp = temp->next;
        }
        return head;
    }
};