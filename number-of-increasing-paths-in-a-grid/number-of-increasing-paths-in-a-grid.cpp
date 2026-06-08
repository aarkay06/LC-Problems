class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid,
            int m, int n, int lastNum) {

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= lastNum)
            return 0;

        if (dp[i][j])
            return dp[i][j];
        int mod = 1e9 + 7;

        lastNum = grid[i][j];
        
        long long ans = 0;
        grid[i][j] = -1;
        ans = (ans + dfs(i - 1, j, dp, grid, m, n, lastNum) ) % mod;
        ans = (ans + dfs(i + 1, j, dp, grid, m, n, lastNum) ) % mod;
        ans = (ans + dfs(i, j - 1, dp, grid, m, n, lastNum) ) % mod;
        ans = (ans + dfs(i, j + 1, dp, grid, m, n, lastNum) ) % mod;
        ans = (ans+1)%mod;
        grid[i][j] = lastNum;
        dp[i][j] = ans;

        return dp[i][j];
    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long ans = 0;
        int mod = 1e9 + 7;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = (ans + dfs(i, j, dp,grid, m, n, 0)) % mod;
            }
        }

        return ans;
    }
};