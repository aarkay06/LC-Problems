# LCM And GCD

## Problem Information
- **Platform:** Geeksforgeeks
- **Difficulty:** Basic
- **URL:** https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1
- **Date:** 2026-04-07

## Solution

```cpp
class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
            int hcf = gcd(a, b);
           vector<int> ans(2);
           ans[0] = ((a*b)/hcf);
           ans[1]=(hcf);
           return ans;
    }
   int gcd(int a, int b){
        if(a == 0) return b;
        return gcd(b%a, a);
    }
};
```

---
*Generated automatically by LeetFeedback Extension*
