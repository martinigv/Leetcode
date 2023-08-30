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
    ListNode* plusOne(ListNode* head) {
        bool iscarry = false;
        vector<ListNode*> v;
        ListNode* temp = head;
        while (temp) {
            v.push_back(temp);
            temp = temp->next;
        }
        temp = v[v.size()-1];
        temp->val++;
        if (temp->val > 9) {
            iscarry = true;
        }
        int tempi = v.size() - 1;
        while (iscarry) {
            temp->val = 0;
            if (temp == head) {
                ListNode* newNode = new ListNode(0,head);
                head = newNode;
                temp = newNode;
            }
            else {
                temp = v[--tempi];
            }
            temp->val++;
            if (temp->val <= 9) {
                iscarry = false;
            }
        }
        return head;
        
    }
    
};