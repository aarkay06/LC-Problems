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
    int maxLevelSum(TreeNode* root) {

        long long maxSum = INT_MIN;
        int maxLevel = 0;
        long long currSum = 0;
        int currLevel = 1;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while (!q.empty()) {
            auto [n, d] = q.front();
            q.pop();

            if (d != currLevel) {
                if (currSum > maxSum) {
                    maxSum = currSum;
                    maxLevel = currLevel;
                }
                currLevel = d;
                currSum = 0;
            }

            currSum += n->val;

            if (n->left != nullptr)
                q.push({n->left, d + 1});
            if (n->right != nullptr)
                q.push({n->right, d + 1});
        }

        if(currSum > maxSum) return currLevel;

        return maxLevel;
    }
};