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
    int pairSum(ListNode* head) {
        vector<int> arr;
        while(head != nullptr){
            arr.push_back(head->val);
            head = head->next;
        }

        int i = 0;int j = arr.size()-1;int maxSum = INT_MIN;
        while(i <=j){
            int sum = arr[i] + arr[j];
            maxSum = max(sum, maxSum);
            i++;
            j--;
        }    

        return maxSum;
    }
};