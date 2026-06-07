class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid, int m, int n) {

        if (i < 0 || i >= m || j < 0 || j >= n)
            return 50000;

        if (dp[i][j])
            return dp[i][j];

        if (i == m - 1 && j == n - 1) {
            return grid[m-1][n-1];
        }
        dp[i][j] = min(dfs(i + 1, j, dp, grid, m, n) + grid[i][j], grid[i][j] + dfs(i, j + 1, dp, grid, m, n));
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        return dfs(0, 0, dp,grid, m, n);
    }
};