# Check if Array Is Sorted and Rotated

## Problem Information
- **Platform:** Leetcode
- **Difficulty:** Easy
- **URL:** https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/submissions/2011133989/
- **Date:** 2026-05-23

## Solution

```cpp
class Solution {
public:
    bool check(vector<int>& nums) {
        int inc = 1;
        int last = INT_MIN;
        int changes = 0;

        for(int i =0; i<nums.size(); i++){
            if(nums[i] < last){
                changes++;
            }
            last = nums[i];
        }

        if(nums[nums.size() -1] > nums[0]) changes++;

        if(changes <= 1) return true;
        else return false;
    }
};
```

---
*Generated automatically by LeetFeedback Extension*
