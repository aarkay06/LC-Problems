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
    int operations(vector<int>& arr) {
        vector<int> arr2 = arr;
        sort(arr2.begin(), arr2.end());
       map<int, int> mp;
        mp[-1] = -1;
        for (int i = 0; i < arr2.size(); i++) {
            mp[arr2[i]] = i;
        }

        int ans = 0;

        for (int i = 0; i < arr2.size(); i++) {
            if (arr[i] != -1) {
                int cycle = 0;
                int curr = i;
                while (true) {
                    if (mp[arr[curr]] != curr) {
                        if (arr[curr] == -1) {
                            cycle--;
                            break;
                        }
                        cycle++;
                        int next = mp[arr[curr]];
                        arr[curr] = -1;
                        curr = next;
                    } else
                        break;
                }

                ans += cycle;
            }
        }

        return ans;
    }

    int minimumOperations(TreeNode* root) {
        vector<int> arr;

        queue<tuple<TreeNode*, int>> q;
        q.push({root, 0});

        int currLevel = 0;
        int opt = 0;

        while (!q.empty()) {
            auto [n, d] = q.front();
            q.pop();

            if (d != currLevel) {
                opt += operations(arr);
                arr.clear();
                arr.push_back(n->val);
                currLevel = d;
            } else
                arr.push_back(n->val);

            if (n->left != nullptr)
                q.push({n->left, d + 1});
            if (n->right != nullptr)
                q.push({n->right, d + 1});
        }

       opt += operations(arr);

        return opt;
    }
};