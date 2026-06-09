class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == 0 ) {
            return 0;
        }

        int fish = grid[i][j];
        
        grid[i][j] = 0;
        int count = fish + (dfs(i - 1, j, grid) + dfs(i + 1, j, grid) +
                            dfs(i, j - 1, grid) + dfs(i, j + 1, grid));

        return count;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                count = max(count, dfs(i, j, grid));
            }
        }
        return count;
    }
};