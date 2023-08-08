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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 리스트의 길이를 알아야 함(m일 때 m-n번쨰 노드를 알아내기 위함)
        //기존 헤드노드는 그대로 두기 위함
        ListNode* hptr = head;
        int length = 1;
        
        while(hptr->next != nullptr) {
            hptr = hptr->next;
            length++;
        }
        // m-n 번째 노드를 찾고
        ListNode* hptr2 = head;
        for (int i = 0; i < length - n - 1; i++) {
            hptr2 = hptr2->next;
        }
        // 지우려는 노드가 몇 번째 인지 알기 위함.
        int num = length - n + 1;
        // 지우려는 노드의 next를 연결해주고 삭제
        // 길이가 1보다 클 경우(next가 존재)
        ListNode* nptr;
        if (num > 1)  
            nptr = hptr2->next;
        // 길이가 1일 경우(next가 null)
        else
            nptr = hptr2;
        if (nptr == hptr2)
            head = nptr->next;
        else if (nptr->next != nullptr)
            hptr2->next = hptr2->next->next;
        else
            hptr2->next = nullptr;
        
        
        return head;
    }
};