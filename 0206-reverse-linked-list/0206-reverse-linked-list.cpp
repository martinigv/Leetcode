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
    //새롭게 생각한 것: 이거 다른 노드들을 차례로 헤드 노드 앞에 놓는 방법 어떨까.
    ListNode* hptr;
    ListNode* tail;
    ListNode* firstTail;
    int count{0};
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        if (tail == head) {
            return head;
        }
        hptr = head;
        if (count < 1) {
            tail = head;
            while(tail->next) {
                tail = tail->next;
            }
        }
        head = hptr->next;
        hptr->next = tail->next;
        tail->next = hptr;
        count++;
        return reverseList(head);
    }
};