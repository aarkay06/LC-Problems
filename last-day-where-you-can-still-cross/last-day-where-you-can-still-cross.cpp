class Solution {
public:
    bool dfs(int r, int c, vector<vector<int>>& cells,
             vector<vector<int>>& grid, int wait, int row, int col,
             vector<vector<bool>>& visited) {
        // cout << "r: " << r << " c: " << c << endl;
        if (r < 0 || r >= row || c < 0 || c >= col || grid[r][c] <= wait ||
            visited[r][c]) {
            return false;
        }

        if (r == row - 1)
            return true;
        visited[r][c] = true;
        bool res = dfs(r + 1, c, cells, grid, wait, row, col, visited) ||
                   dfs(r - 1, c, cells, grid, wait, row, col, visited) ||
                   dfs(r, c - 1, cells, grid, wait, row, col, visited) ||
                   dfs(r, c + 1, cells, grid, wait, row, col, visited);
        return res;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // cout << "ROWS: " << row<< " COL: " << col << "\n";
        vector<vector<int>> grid(row, vector<int>(col, 0));
       
        for (int i = 0; i < cells.size(); i++) {
            vector<int> arr = cells[i];
            int j = arr[0];
            int k = arr[1];
            grid[j - 1][k - 1] = i + 1;
        }
        int start = 0;
        int end = row * (col );
        int ans;
        while (start <= end) {
             vector<vector<bool>> visited(row, vector<bool>(col, false));
            int mid = start + (end - start) / 2;
            int res = false;
            for (int i = 0; i < col; i++) {
                res = dfs(0, i, cells, grid, mid, row, col, visited);
                if (res == true)
                    break;
            }
            if (res) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};