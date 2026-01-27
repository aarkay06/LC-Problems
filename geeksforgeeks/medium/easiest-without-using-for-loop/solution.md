# EASIEST WITHOUT USING FOR LOOP

## Problem Information
- **Platform:** Geeksforgeeks
- **Difficulty:** Medium
- **URL:** https://www.geeksforgeeks.org/problems/level-order-traversal/1
- **Date:** 2026-01-27

## Solution

```cpp
    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // code here
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!(q.empty())){
            int len = q.size();
            vector<int> level;
            for(int i=0; i<len; i++){
                Node* node = q.front();
                q.pop();
                level.push_back(node->data);
                if(node->left != NULL) q.push(node->left);
                 if(node->right != NULL) q.push(node->right);
            } 
            ans.push_back(level);
        }
        return ans;
    }
};
```

---
*Generated automatically by LeetFeedback Extension*
