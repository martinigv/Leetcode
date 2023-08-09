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
        // example 2
        if (lists.empty())
            return nullptr;
        // example 3
        if (lists.size() == 1 && lists[0] == nullptr)
            return nullptr;
    
        vector<int> v{};
        ListNode* l1;
        // copy value in linked lists to vector;
        for (int i = 0; i < lists.size(); i++) {
            l1 = lists[i];
            while (l1 != nullptr) {
                v.push_back(l1->val);
                l1 = l1->next;
            }
        }
        // sort values in vector;
        sort(v.begin(), v.end());
        /*for (auto a : v)
            cout << a;
        */

        //make one linkedlist;
        ListNode* hl;
        ListNode* l2;
        ListNode* temp;
        hl = lists[0]; // [[1]] case, doesn't work for statement;
        for (int i = 0; i < lists.size()-1; i++) {
            l2 = lists[i];
            if (l2 != nullptr) {
                while (l2->next != nullptr) {
                    l2 = l2->next;
                }
                l2->next = lists[i + 1];
                temp = l2;
            }
            else if (hl == nullptr) {
                hl = lists[i + 1];
            }
            else {
                temp->next = lists[i + 1];
            }
        }
        // change linkedlist values to vector values; 
        ListNode* temp2 = hl;
        for (int i = 0; temp2 != nullptr; i++) {
            temp2->val = v[i];
            temp2 = temp2->next;
        }
        return hl;
    }
 };