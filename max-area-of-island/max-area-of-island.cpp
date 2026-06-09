class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int& sum) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == 0) {
            return 0;
        }

        grid[i][j] = 0;

       int s=  dfs(i - 1, j, grid, sum) + dfs(i + 1, j, grid, sum) +
               dfs(i, j - 1, grid, sum) + dfs(i, j + 1, grid, sum) +1;
               sum = max(s, sum);
               return s;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
          int sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1)
                     dfs(i, j, grid, sum);
            }
        }
        return sum;
    }
};