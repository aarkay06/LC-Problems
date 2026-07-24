class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        int left = -1;
        for (int i = 0; i < n; i++) {
              left = max(left, h[i]);
              leftMax[i] = left;
        }

        int right = -1;
        for (int i = n-1; i >= 0; i--) {
              right = max(right, h[i]);
              rightMax[i] = right;
        }

        int ans = 0;

        for (int i = 1; i < n-1; i++) {
              ans += min(leftMax[i], rightMax[i]) - h[i];
        }

        return ans;
    }
};