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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<long long> sum;
        queue<tuple<TreeNode*, int, TreeNode*, int>> q;
        q.push({root, 0, root, 0});

        while (!q.empty()) {
            auto [n, d, p, i] = q.front();
            q.pop();

            if (d >= sum.size()) {
                sum.push_back(n->val);
            } else
                sum[d] += n->val;

            if (n->left != nullptr)
                q.push({n->left, d + 1, n, 0});
            if (n->right != nullptr)
                q.push({n->right, d + 1, n, 0});
        }

        for (int i = 0; i < sum.size(); i++) {
            cout << sum[i] << " ";
        }

        q.push({root, 0, root, 0});

        while (!q.empty()) {
            auto [n, d, p, i] = q.front();
            q.pop();

            int nodesum = 0;
            if (d == 0) {
                n->val = 0;
            } else if (i == 1) {
                if (p->left != nullptr)
                    nodesum += p->left->val;
                if (p->right != nullptr)
                    nodesum += p->right->val;
                // cout << "for node: " << n->val << " sum: " << sum[d]
                //      << " and nodesum: " << nodesum << "\n";
                if (p->left != nullptr)
                     p->left->val = sum[d] - nodesum;
                if (p->right != nullptr)
                    p->right->val = sum[d] - nodesum;
            }

            if (n->left != nullptr)
                q.push({n->left, d + 1, n, 1});
            if (n->right != nullptr) {
                if (n->left == nullptr)
                    q.push({n->right, d + 1, n, 1});
                else
                    q.push({n->right, d + 1, n, 2});
            }
        }

        return root;
    }
};