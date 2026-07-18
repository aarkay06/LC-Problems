# Palindromic Permutations

## Problem Information
- **Platform:** Geeksforgeeks
- **Difficulty:** Medium
- **URL:** https://www.geeksforgeeks.org/problems/pallindrome-patterns0809/1
- **Date:** 2026-07-18

## Solution

```cpp
        for (int i = 0; i<26; i++) {
            for (int j = 0; j < arr[i] /2; j++) {
                str += (i + 'a');
            }
            if (arr[i] %2 != 0)
                odd = i + 'a';
        }
        vector<string> res;
        do  {
            string temp = str;
            string reversetemp = temp;
            reverse(reversetemp.begin(), reversetemp.end());
            if (s.size() %2 != 0) {
                temp = temp + odd + reversetemp ;
            } else {
                temp = temp + reversetemp;
            }
            res.push_back(temp);
        }   while (next_permutation(str.begin(), str.end()));
        return res;
    }
};
```

---
*Generated automatically by LeetFeedback Extension*
