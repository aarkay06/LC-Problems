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
    void insert(TreeNode* root, int val) {
        if (!root->left && root->val > val)
            root->left = new TreeNode(val);

        if (!root->right && root->val < val)
            root->right = new TreeNode(val);

        if(root->left && root->val > val) insert(root->left, val);
        if(root->right && root->val < val) insert(root->right, val);
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) 
            root = new TreeNode(val);
        insert(root, val);
        return root;
    }
};