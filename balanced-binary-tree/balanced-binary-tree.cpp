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
    int treeSize(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = 0, right = 0;
        // if (root->left)

        left = treeSize(root->left);
        // if (root->right)
        right = treeSize(root->right);
        if (left ==-1 || right == -1)
            return -1;
        cout << "Left: " << left << ", right: " << right;
        if (abs(left - right) > 1)
            return -1;
        else
            return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        int size = treeSize(root);
        cout << "size: " << size;
        if (size == -1)
            return false;
        return true;
    }
};