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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* temp;
        temp = head->next;
        head->next = swapPairs(head->next->next); 
        temp->next = head;

        return temp;
        /*Original List: 1 -> 2 -> 3 -> 4 -> 5 -> 6

        First, 1 and 2 are considered:
        1's next is updated to the result of the recursive call, swapPairs(3->4->5->6).
        2's next is updated to 1.
        So, after the first call, the list is 2 -> 1 -> (result of swapping 3->4->5->6)

        Next, 3 and 4 are considered within the recursive call:
        3's next is updated to the result of the recursive call, swapPairs(5->6).
        4's next is updated to 3.
        So, after this recursive call, the list is 2 -> 1 -> 4 -> 3 -> (result of swapping 5->6)

        Then, 5 and 6 are considered:
        5's next is updated to the result of the recursive call, but since there are no more pairs left, it remains nullptr.
        6's next is updated to 5.
        So, after this recursive call, the list becomes 2 -> 1 -> 4 -> 3 -> 6 -> 5.

        There are no more nodes left to swap, so the recursion unwinds and the final swapped list is 2 -> 1 -> 4 -> 3 -> 6 -> 5.

        Share
        Save



        */
    }
};