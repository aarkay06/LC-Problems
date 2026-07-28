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
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> s;
        set<int> duplicates;

        while(head){
            if(s.contains(head->val)) duplicates.insert(head->val);
            s.insert(head->val);
            head= head->next;
        }

    ListNode* last = nullptr;
    
     for (auto it = s.begin(); it != s.end(); it++){
        if(duplicates.contains(*it)) continue;
        
            ListNode* n = new ListNode(*it);
            if(last) last->next = n;
            else head  = n;
            last = n;
        }

              return head;
    }

  
};