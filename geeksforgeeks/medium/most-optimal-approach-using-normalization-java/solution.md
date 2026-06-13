# Most Optimal Approach using Normalization! - Java

## Problem Information
- **Platform:** Geeksforgeeks
- **Difficulty:** Medium
- **URL:** https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
- **Date:** 2026-06-13

## Solution

```cpp
            auto[r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                // i=0: (-1, 0) -> Up
                // i=1: ( 0, 1) -> Right
                // i=2: ( 1, 0) -> Down
                // i=3: ( 0,-1) -> Left
                int nr = r + dirs[i];
                int nc = c + dirs[i + 1];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col) {
                    if (!visited[nr][nc] && board[nr][nc] != 0) {
                        visited[nr][nc] = 1;
                        q.push({nr, nc});
                        x1 = min(x1, nr);
                        x2 = max(x2, nr);
                        y1 = min(y1, nc);
                        y2 = max(y2, nc);
                    }
                }
            }
        }
            unique.push_back({x1, x2, y1, y2});
    }
    int countDistinctIslands(vector<vector<int>> & board) {
        // code here
        int row = board.size();
```

---
*Generated automatically by LeetFeedback Extension*
