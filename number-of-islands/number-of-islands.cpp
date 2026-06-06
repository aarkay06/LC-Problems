class Solution {
public:
    void bfs(int m, int n, vector<vector<char>>& grid,vector<vector<bool>>& visited) {
        visited[m][n] = 1;

        if (m > 0 && !visited[m - 1][n] && grid[m - 1][n] == '1')
            bfs(m - 1, n, grid, visited);

        if (m < grid.size() - 1 && !visited[m + 1][n] && grid[m + 1][n] == '1')
            bfs(m + 1, n, grid, visited);

        if (n > 0 && !visited[m][n - 1] && grid[m][n - 1] == '1')
            bfs(m, n - 1, grid, visited);

        if (n < grid[0].size() - 1 && !visited[m][n + 1] &&
            grid[m][n + 1] == '1')
            bfs(m, n + 1, grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(), 0));
        int count = 0;

        for (int i = 0; i < visited.size(); i++) {
            for (int j = 0; j < visited[i].size(); j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    bfs(i, j, grid, visited);
                    count++;
                }
            }
        }

        return count;
    }
};