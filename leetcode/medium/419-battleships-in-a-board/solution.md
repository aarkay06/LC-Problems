# Battleships in a Board

## Problem Information
- **Platform:** Leetcode
- **Difficulty:** Medium
- **URL:** https://leetcode.com/problems/battleships-in-a-board/submissions/2027939005/
- **Date:** 2026-06-09

## Solution

```cpp
class Solution {
public:
    int dfs(int i, int j, vector<vector<char>>& board) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] == '.') {
            return 1;
        }

        board[i][j] = '.';

        dfs(i - 1, j, board);
        dfs(i + 1, j, board);
        dfs(i, j - 1, board);
        dfs(i, j + 1, board);
        return 1;
    }

    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'X')
                    count += dfs(i, j, board);
            }
        }
        return count;
    }
};
```

---
*Generated automatically by LeetFeedback Extension*
