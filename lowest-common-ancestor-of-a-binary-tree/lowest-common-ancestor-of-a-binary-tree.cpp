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
    vector<int> pTree;
    vector<int> qTree;
     TreeNode* ansNode;

    void traverse(TreeNode* root, TreeNode* r, vector<int>& treeArr, int in) {
        if (!root)
            return;
        treeArr.push_back(root->val);
        if (root->val == r->val) {
            if (in == 0)
                pTree = treeArr;
            if (in == 1)
                qTree = treeArr;
            return;
        }
        traverse(root->left, r, treeArr, in);
        traverse(root->right, r, treeArr, in);
        treeArr.pop_back();
    }

   
    void node(TreeNode* root, int val){
         if (!root)
            return;
        if (root->val == val) {
            ansNode =  root;
            return;
        }
        node(root->left, val);
        node(root->right, val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> arr;
        traverse(root, p, arr, 0);
        arr.clear();
        traverse(root, q, arr, 1);

        int size1 = pTree.size();
        int size2 = qTree.size();

     
        int ans;
        for (int i = 0; i < min(size1, size2); i++) {
            if (pTree[i] == qTree[i])
                ans = pTree[i];
        }

node(root, ans);
        return ansNode;
    }
};