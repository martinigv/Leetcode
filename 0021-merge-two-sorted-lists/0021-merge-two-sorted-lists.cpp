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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* standNode;
        ListNode* otherNode;
        if (list1 != nullptr || list2 != nullptr) {
            if (list1 != nullptr && list2 != nullptr) {
                if (list1->val >= list2->val) {
                    standNode = list2;
                    otherNode = list1;
                }
                else {
                    standNode = list1;
                    otherNode = list2;
                }
            }
            else if (list1 != nullptr) {
                standNode = list1;
                return standNode;
            }
            else {
                standNode = list2;
                return standNode;
            }
        }
        else {
            return nullptr;
        }
        vector<int> v{};
        while(list1 != nullptr || list2 != nullptr) {
            if (list1 != nullptr) {
                v.push_back(list1->val);
                list1 = list1->next;
            }
            if (list2 != nullptr) {
                v.push_back(list2->val);
                list2 = list2->next;
            }
        }
        sort(v.begin(), v.end());
        // make two linked lists to one;
        ListNode* hOtherNode = otherNode;
        while (otherNode->next != nullptr) {
            otherNode = otherNode->next;
        }
        otherNode->next = standNode->next;
        standNode->next = hOtherNode;
        // insert values in v to linkedlist;
        ListNode* hStandNode = standNode;
        for (int i = 0; standNode != nullptr; i++) {
            standNode->val = v[i];
            standNode = standNode->next;
        }
        return hStandNode;
    }
};