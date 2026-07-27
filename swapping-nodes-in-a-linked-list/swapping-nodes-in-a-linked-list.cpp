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
    ListNode* n1 = nullptr;
    ListNode* n2 = nullptr;
    int size = 0;
    void recursion(ListNode* head, int k, int i) {

        if (head == nullptr){
          
            
            // cout << "size is: " << size << "\n";
              return; }
        else {
            // cout << "i: " << i << " val: " << head->val << "\n";
            size++;
            if (i == k)
                n1 = head;
            recursion(head->next, k, i + 1);
        }
        // cout << "k " << i-size << " val: " << head->val << "\n";
        if (size - i + 1 == k)
            n2 = head;
        
    }

    ListNode* swapNodes(ListNode* head, int k) {
        recursion(head, k, 1);
        int temp = n1->val;
        n1->val = n2->val;
        n2->val = temp;
        return head;
    }
};