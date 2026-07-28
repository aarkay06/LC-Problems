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
    ListNode* n;
    bool recursion(ListNode* head) {
        if (!head)
            return true;

        if (head->next == nullptr) {
            if (n->val != head->val)
                return false;
            n = n->next;
            return true;
        }

        bool r = recursion(head->next);

        if (n->val != head->val) {
            n = n->next;
            return false;
        }
        n = n->next;
        return r && true;
    }
    bool isPalindrome(ListNode* head) {
        n = head;
       return recursion(head);
    };
};