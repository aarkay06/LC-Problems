# Number of Subarrays with Bounded Maximum

## Problem Information
- **Platform:** Leetcode
- **Difficulty:** Medium
- **URL:** https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/
- **Date:** 2026-03-12

## Solution

```cpp
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int j = 0;
        int ans = 0;
        int lastGreaterThanRight = -1;
        int lesserThanLeft = 0;

        while (j < nums.size()) {

            if (nums[j] > right) {

                int n = (j - lastGreaterThanRight - 1);
                ans += (n * (n + 1)) / 2;
                ans -= (lesserThanLeft * (lesserThanLeft + 1)) / 2;
                lesserThanLeft = 0;
                lastGreaterThanRight = j;
            } else if (nums[j] < left) {
                lesserThanLeft++;
            } else {
                ans -= (lesserThanLeft * (lesserThanLeft + 1)) / 2;
                lesserThanLeft = 0;
            }

            j++;
        }

        long long n = (int)nums.size() - 1 - lastGreaterThanRight;
        ans += (n * (n + 1)) / 2;
        ans -= (lesserThanLeft * (lesserThanLeft + 1)) / 2;

        return ans;
    }
};
```

---
*Generated automatically by LeetFeedback Extension*
