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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL)
            return head;
        ListNode *h = head;
        ListNode *fast = head;
        ListNode *slow = head;

        int middle = 1;
        int size;
        while (fast && fast->next)
        {
            middle++;
            fast = fast->next->next;
            slow = slow->next;
        }
        cout << "middle index: " << middle << endl;
        // cout << "Last Element: " << fast->val << endl;
        if (fast == NULL)
        {
            size = (middle - 1) * 2;
        }
        else
        {

            size = (middle * 2) - 1;
        }
        cout << "We were here with size: " << size << endl;
        if (n > size)
            return head;

        cout << "Middle Element: " << slow->val << endl;
        cout << "index to delete: " << size - n + 1 << endl;
        if (size - n + 1 > middle)
        {
            ListNode *last = slow;
            while (size - n + 1 != middle && slow->next)
            {
                last = slow;
                slow = slow->next;
                middle++;
            }
            last->next = slow->next;
        }
        else
        {
            middle = 1;
            if (middle == size - n + 1)
            {
                head = head->next;
                return head;
            }
            ListNode *last = head;
            while (size - n + 1 != middle && h->next)
            {
                last = h;
                h = h->next;
                middle++;
            }

            last->next = h->next;
        }
        return head;
    }
};