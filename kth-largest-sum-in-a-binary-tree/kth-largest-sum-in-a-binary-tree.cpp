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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sum;
        if (root == nullptr)
            return -1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto [n, d] = q.front();
            q.pop();
            if (sum.size()  <= d)
                sum.push_back(n->val);
            else
                sum[d] += n->val;

            if(n->left != nullptr) q.push({n->left, d+1});
            if(n->right != nullptr) q.push({n->right, d+1});
        }
        if(k > sum.size()) return -1;
        sort(sum.begin(), sum.end());
        
        return sum[sum.size() - k];
    }
};