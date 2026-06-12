class Solution {
public:
    bool dfs(int i, int j, char c, int len, vector<vector<char>>& grid,
             vector<vector<int>>& visited) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] != c)
            return false;
        if (visited[i][j] && (len - visited[i][j]) >= 4)
            return true;
        else if (visited[i][j])
            return false;

        visited[i][j] = len;
        return dfs(i+1, j, c, len + 1, grid, visited) ||
               dfs(i - 1, j, c, len + 1, grid, visited) ||
               dfs(i, j + 1, c, len + 1, grid, visited) ||
               dfs(i, j - 1, c, len + 1, grid, visited);
    }

    bool containsCycle(vector<vector<char>>& grid) {
        unordered_set<char> set;
        vector<vector<int>> visited(grid.size(),
                                    vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                // if (!set.contains(grid[i][j])) {
                // set.insert(grid[i][j]);
                if (dfs(i, j, grid[i][j], 1, grid, visited)) {
                    return true;
                }
                // }
            }
        }
        return false;
    };
};