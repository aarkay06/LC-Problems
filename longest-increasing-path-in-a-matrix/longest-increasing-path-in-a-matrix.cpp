class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid,
            int m, int n, int lastNum, int& largest) {

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= lastNum)
            return 0;

        if (dp[i][j])
            return dp[i][j];

        lastNum = grid[i][j];
        int length = 0;
        grid[i][j] = -1;
        length = max(length, dfs(i - 1, j, dp, grid, m, n, lastNum, largest));
        length = max(length, dfs(i + 1, j, dp, grid, m, n, lastNum, largest));
        length = max(length, dfs(i, j - 1, dp, grid, m, n, lastNum, largest));
        length = max(length, dfs(i, j + 1, dp, grid, m, n, lastNum, largest));
        length++;

        grid[i][j] = lastNum;
        dp[i][j] = length;
        largest = max(largest, length);
    

        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int largest = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, dp, grid, m, n, -1, largest);
            }
        }

        return largest;
    }
};