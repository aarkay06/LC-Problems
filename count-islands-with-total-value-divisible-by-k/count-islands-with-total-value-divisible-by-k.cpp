class Solution {
public:
    long long bfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == 0)
            return 0;

        long long val = grid[i][j];
        grid[i][j] = 0;
        long long ans = val + bfs(i - 1, j, grid) + bfs(i + 1, j, grid) +
                  bfs(i, j - 1, grid) + bfs(i, j + 1, grid);

        return ans;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != 0) {
                    long long res = bfs(i, j, grid);
                    if (res % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
};