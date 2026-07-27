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
    // two pointers
    // when first pointer is at 0 (1st from left), second pointer at k-1 (kth
    // from start) when second pointer at end, first pointer at kth from last
    //  1 2 3 4 5 6 7 8
    //  s . . . . . f
    //    s . . . . . f

    // 1 2 3 4 5 6 7 8
    // s . . f
    //         s . . f
    // initially s at 0, move both until f at end, s will be at answer
    // two pointers but their distance has to be the same, both will move 1 node
    // at a time

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* n1;
        ListNode* n2;

        ListNode* slow = head;
        ListNode* fast = head;

        // k-1 cause we are moving ahead k-1 times
        // basically if k = 3
        // we have to move AHEAD from the head node only twice

        for (int i = 0; i < k - 1; i++) {
            fast = fast->next;
        }

        n1 = fast;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        n2 = slow;

        int temp = n2->val;
        n2->val = n1->val;
        n1->val = temp;

        return head;
    }
};