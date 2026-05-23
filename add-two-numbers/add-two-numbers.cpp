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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        string s1, s2, s3;
        while (l1 != NULL)
        {
            s1.push_back(l1->val + '0');
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            s2.push_back(l2->val + '0');
            l2 = l2->next;
        }

        if (s1.size() > s2.size())
        {
            s3 = s2;
            s2 = s1;
            s1 = s3;
        }
        ListNode *head = new ListNode(-1);
        ListNode *ans = head;

        int rem = 0;
        int i = 0;
        int j = 0;

        while (i <= s2.size() - 1  && j <= s1.size() - 1)
        {
            int sum = (s1[j] - '0') + (s2[i] - '0') + rem;

            rem = 0;
            if (sum > 9)
            {
                rem = 1;
                sum -= 10;
            }
           
            ListNode *newNode = new ListNode();
            newNode->val = sum;
            if(head->val == -1) ans = newNode;
            head->next =  newNode;
            head = newNode;
            i++;
            j++;
        }

        cout << "i: " << i << " j: " << j;
        while (i <= s2.size() - 1)
        {
            int sum = (s2[i] - '0') + rem;
            rem = 0;
            if(sum >= 10) {
                sum-= 10;
                rem = 1;
            }
            ListNode *newNode = new ListNode(sum);
            head->next = newNode;
            head = newNode;
            i++;
        };

        if(rem == 1){
             ListNode *newNode = new ListNode(1);
            head->next = newNode;
            head = newNode;
        }
        return ans;
    }
};