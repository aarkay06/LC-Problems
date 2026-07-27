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
    vector<int> val;

    void recursion(int i, int left, int right, ListNode* head) {

        if (i == right) {
            val.push_back(head->val);
            head->val = val[0];
            return;
        }

        if (i < right && i >= left) 
            val.push_back(head->val);
            
        recursion(i + 1, left, right, head->next);

        if (i >= left)
            head->val = val[right - i];
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 1st idea:
        // swap left, right
        // swap left+1, right-1
        // swap lef+2, right-2

        // we will store the values in an array starting from left
        // after reaching right we will go back and start putting values from
        // starting

        recursion(1, left, right, head);
        return head;
    }
};