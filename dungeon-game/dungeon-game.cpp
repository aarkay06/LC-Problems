class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& dungeon,
            int m, int n) {

        if (i < 0 || i >= m || j < 0 || j >= n)
            return 30000;

        if (dp[i][j])
            return dp[i][j];

        if (i == m - 1 && j == n - 1) {
            return dungeon[i][j] < 0 ? abs(dungeon[i][j]) + 1 : 1;
        }

        int curr = dungeon[i][j];
        int down = dfs(i + 1, j, dp, dungeon, m, n);
        int right = dfs(i, j + 1, dp, dungeon, m, n);
        //down and right will always be greater than 0
        // if(curr < 0){
        //     if(abs(curr) +1 > down){
        //         down = abs(curr) + 1;
        //     }
        //     if(abs(curr) + 1 > right){
        //         right = abs(curr) + 1;
        //     }
        // }

        dp[i][j] = min(max(1,down-curr),max(1, right-curr));
        return dp[i][j];
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        return dfs(0, 0, dp, dungeon, m, n);
    }
};