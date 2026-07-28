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
    ListNode* reverseK(ListNode* head, int k) {
        // Reverse K nodes
        // 1 2 3 4
        // 4 3 2 1
        // and return 4 to be then added back as the next of the last element

        ListNode* first = head;
        ListNode* last = nullptr;
        ListNode* temp = head;

        while (temp && k) {
            ListNode* next = temp->next;
            temp->next = last;
            last = temp;
            temp = next;
            k--;
        }

        first->next = temp;
        return last;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // The reverse function perfectly reverse k elements starting from any
        // node We'll just feed it every kth element for the first element, just
        // mark count = k for easier calculation of count % k == 0 for every kth
        // element

        vector<ListNode*> v;
        int count = k;
        while (head) {
            if (count % k == 0) {
                v.push_back(head);
            }
            count++;
            head = head->next;
        }

        // delete the last node in case the count isnt divisible by k
        // there wont be k elements starting from this node
        if (count % k != 0)
            v.pop_back();

        ListNode* ans;
        for (int i = 0; i < v.size(); i++) {
            if (i == 0)
                ans = reverseK(v[i], k);
            if (i != 0) {

                // The node that is being processed rn will be the last element
                // in its chain upon reversal thats why when the next part will
                // be reversed, it will be linked to this element.
                v[i - 1]->next = reverseK(v[i], k);
            }
        }

        return ans;
    }
};