/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> vals;
    vector<int> inorderTraversal(TreeNode* root) {
        read(root);
        return vals;
    };

    void read(TreeNode* root) {
        if (!root)
            return;
        read(root->left);
        vals.push_back(root->val);
        read(root->right);
    }
};