class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid,int& count, int& total, int curr) {

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == -1 )
            return;

        int a = grid[i][j];

        if (a == 2 ) {
            if(curr-1 == total) count++;
            return;
        }

        grid[i][j] = -1;
        dfs(i - 1, j, grid, count, total, curr+1);
        dfs(i + 1, j, grid, count, total, curr+1);
        dfs(i, j - 1, grid, count, total, curr+1);
        dfs(i, j + 1, grid, count, total, curr+1);

        grid[i][j] = a;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int count =0;
        int total = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    total++;
                }
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, count, total, 0);
                    break;
                }
            }
        }

        return count;
    }
};