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
    void largest(TreeNode* root, int val, int& min) {

        if (root->val > val && (root->left == nullptr)) {
            if (min == INT_MIN)
                min = -1;

            return;
        }

        if (root->val == val) {
            min = val;
            return;
        }

        if (root->val < val)
            min = root->val > min ? root->val : min;
        if (root->val < val && root->right)
            largest(root->right, val, min);

        if (root->val > val && root->left) {
            largest(root->left, val, min);
        }
    }
    void smallest(TreeNode* root, int val, int& max) {
        cout << root->val << " ";

        if (root->val < val && (root->right == nullptr)) {
            if (max == INT_MAX)
                max = -1;

            return;
        }
        if (root->val == val) {
            max = val;
            return;
        }

        if (root->val > val) {
            if (root->val < max)
                max = root->val;
        }
        if (root->val > val && root->left)
            smallest(root->left, val, max);

        if (root->val < val && root->right) {
            smallest(root->right, val, max);
        }
    }

    int lowerBound(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] >= target) {
                ans = mid;
                r = mid - 1; // look for a smaller valid index
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    void tree(TreeNode* root, vector<int>& arr) {
        if (root)
            arr.push_back(root->val);
        if (root->left)
            tree(root->left, arr);
        if (root->right)
            tree(root->right, arr);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> arr;
        vector<int> array;
        tree(root, array);

        sort(array.begin(), array.end());

        for (int i = 0; i < queries.size(); i++) {
            int max = lowerBound(array, queries[i]);
            int min;
            if (max == -1)
                min = array[array.size() - 1];
            else if (array[max] == queries[i])
                min = array[max];
            else
                if(max == 0) min = -1;
                else min = array[max-1];

            arr.push_back(
                {min , max == -1 ? -1 : array[max]});
        }

        return arr;
    }
};