class Solution {
public:
    int bfs(int i, int j, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int row = grid.size();
        int col = grid[0].size();

        q.push({i, j});

        bool walkOff = false;
        int countof1 = 1;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            int dirs[5] = {-1, 0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                // i=0: (-1, 0) -> Up
                // i=1: ( 0, 1) -> Right
                // i=2: ( 1, 0) -> Down
                // i=3: ( 0,-1) -> Left
                int nr = r + dirs[i];
                int nc = c + dirs[i + 1];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
                    walkOff = true;
                    continue;
                }
                if (grid[nr][nc] != 0) {
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                    countof1++;
                }
            }
        }

        return walkOff ? 0 : countof1;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    count += bfs(i, j, grid);
                }
            }
        }

        return count;
    }
};