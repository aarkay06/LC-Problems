# Multiply 2 matrices

## Problem Information
- **Platform:** Geeksforgeeks
- **Difficulty:** Medium
- **URL:** https://www.geeksforgeeks.org/problems/multiply-2-matrices4144/1
- **Date:** 2026-02-23

## Solution

```cpp
class Solution {
  public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        // Code here
        int n = mat1[0].size();
        vector<vector<int>> res(n,vector<int> (n,0) );
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int sum =0;
                for(int k=0; k<n; k++){
                    sum +=( mat1[i][k] * mat2[j][k]);
                }
                res[i][j] = sum;
            }
        }
        return res;
    }
};
```

---
*Generated automatically by LeetFeedback Extension*
