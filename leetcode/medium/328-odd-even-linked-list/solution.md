# Odd Even Linked List

## Problem Information
- **Platform:** Leetcode
- **Difficulty:** Medium
- **URL:** https://leetcode.com/problems/odd-even-linked-list/submissions/1895729666/
- **Date:** 2026-01-24

## Solution

```cpp
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
  ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenC = head->next;
        ListNode *oddC = head;
        int count = 1;
        while (head)
        {
            if (count > 2 && count % 2 == 0)
            {
                even->next = head;
                even = head;
            }
            else if (count > 2 && count % 2 != 0)
            {
                odd->next = head;
                odd = head;
            }
            count++;
            head = head->next;
        }

        odd->next = evenC;
                even->next = NULL;
        return oddC;
    }
};
```

---
*Generated automatically by LeetFeedback Extension*
