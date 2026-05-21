# Count Good Numbers

## Problem Information
- **Platform:** Leetcode
- **Difficulty:** Medium
- **URL:** https://leetcode.com/problems/count-good-numbers/submissions/2009362211/
- **Date:** 2026-05-21

## Solution

```cpp
class Solution {
public:
long long binExpo(long long a, long long b, long long mod)
{
    long long result = 1;

    a %= mod;

    while (b > 0)
    {
        // if b is odd
        if (b & 1)
        {
            result = (result * a) % mod;
        }

        a = (a * a) % mod;

        b >>= 1; // divide b by 2
    }

    return result;
}
    int countGoodNumbers(long long n) {
        long long count = 1;
        int m = 1e9 + 7;
        if (n == 0)
            return count;
        if (n >= 1) {
                count = (count % m * binExpo(5, (n+1)/2, m) % m);
        }
        if (n >= 2) {
                 count = (count % m * binExpo(4, (n)/2, m) % m);
       
        }
        return count;
    }
};
```

---
*Generated automatically by LeetFeedback Extension*
