class Solution {
public:
       int dfs(int i, int j, vector<vector<int>>& dp, int m, int n) {

        if (i < 0 || i >= m || j < 0 || j >= n)
            return 0;

        if(dp[i][j]) return dp[i][j];

        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        dp[i][j] = dfs(i + 1, j, dp, m, n) +
                   dfs(i, j + 1, dp, m, n);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
          vector<vector<int>> dp(m, vector<int>(n));
       return  dfs(0, 0, dp, m, n);
    }
};