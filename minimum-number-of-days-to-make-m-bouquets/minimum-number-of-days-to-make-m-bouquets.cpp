class Solution {
public:
    bool isValid(vector<int>& bloom, int k, int m, int day) {
        int flowers = 0, bouque = 0;
        for (int i = 0; i < bloom.size(); i++) {
            if (bloom[i] <= day) {
                flowers++;
            } else {
                bouque += flowers / k;
                flowers = 0;
            }
        }
        bouque += flowers / k;
        return bouque >= m;
    }

    int minDays(vector<int>& bloom, int m, int k) {
        int min = 1;
        int max = *max_element(bloom.begin(), bloom.end());
        int days = -1;
        while (min <= max) {
            int mid = (min + max) / 2;
            if (isValid(bloom, k, m, mid)) {
                max = mid - 1;
                days = mid;
            } else {
                min = mid + 1;
            }
        }
        return days;
    }
};