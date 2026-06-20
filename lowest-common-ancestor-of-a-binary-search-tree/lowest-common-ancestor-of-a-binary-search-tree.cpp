/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    void traverse(TreeNode* root, int v1, int v2) {
        if (root) {
            int val = root->val;
            if ((v1 >= val && v2<=val) || (v1 <= val && v2>=val) ) {
                ans = root;
            }

            if (v1 < val && v2 < val) {
                ans = root;
                if (root->left)
                    traverse(root->left, v1, v2);
            }
            if (v1 > val && v2 > val) {
                ans = root;
                if (root->right)
                    traverse(root->right, v1, v2);
            }
        }
    };

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root, p->val, q->val);

        return ans;
    }
};