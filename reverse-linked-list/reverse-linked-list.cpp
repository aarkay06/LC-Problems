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
    ListNode* reverseList(ListNode* head) {
  
        //reverse with while loop
        ListNode* last = nullptr;
        ListNode* temp = head;

        while(temp){
            ListNode* next = temp->next;
            temp->next = last;
            last = temp;
            temp = next;
        }

        return last;

        // REVERSING WITH RECURSION
        //we have to return the last element
        //so base case is basically return the last element 
        //and keep returning it afterwards too

        //also 1 has no next, so a hint that for every element..
        //..mark its next element's Next as this very element
        //and not mark the current element's next otherwise 1 will also have a next element 
        //which shouldnt be the case

        // if (head == NULL ||head->next == NULL)
        //     return head;
        // ListNode* temp = head;
        // ListNode* back = reverseList(head->next);
        // temp->next->next = temp;
        // head->next = NULL;
        // return back;
    }
};