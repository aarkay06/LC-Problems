class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == 1)
            return 0;

        if(dp[i][j]) return dp[i][j];

        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return 1;
        }
        dp[i][j] = dfs(i + 1, j, dp, grid) +
                   dfs(i, j + 1, dp, grid);
        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int count = 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
       return  dfs(0, 0, dp, grid);
    }
};