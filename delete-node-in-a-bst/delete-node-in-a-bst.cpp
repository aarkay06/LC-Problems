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
    TreeNode* parent;
    bool flag;
    void traversal(TreeNode* root, int key) {
        if (root->val == key && parent == nullptr) {
            if (root->right) {
                root->left = root = root->right;
            } else if (root->left)
                root = root->left;
            else
                root = nullptr;
        }

        if (root->val == key) {
            if (flag) {
                parent->right = root->right;
                if (root->left)
                    root->right->left = root->left;
            } else
                parent->left = root->right;
            if (root->left)
                root->right->left = root->left;
        }

        parent = root;

        if (root->val > key)
            if (root->left) {
                traversal(root->left, key);
                flag = 0;
            }

        if (root->val < key)
            if (root->right) {
                traversal(root->right, key);
                flag = 1;
            }
    }

    void treeToArr(TreeNode* root, vector<int>& arr, int key) {
        if (!root)
            return;
        treeToArr(root->left, arr, key);
        if (!(root->val == key))
            arr.push_back(root->val);
        treeToArr(root->right, arr, key);
    }

    TreeNode* buildBST(const vector<int>& arr, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = buildBST(arr, start, mid - 1);
        root->right = buildBST(arr, mid + 1, end);

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<int> arr;
        if (root)
            treeToArr(root, arr, key);
        
       root =  buildBST(arr, 0, arr.size() - 1);

        return root;
    }
};