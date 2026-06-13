class Solution {
public:
    void bfs(vector<vector<char>>& board, vector<vector<bool>>& visited) {
        int row = board.size();
        int col = board[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O' &&
                    (i == 0 || j == 0 || i == row - 1 || j == col - 1)) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto[r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                // i=0: (-1, 0) -> Up
                // i=1: ( 0, 1) -> Right
                // i=2: ( 1, 0) -> Down
                // i=3: ( 0,-1) -> Left
                int nr = r + dirs[i];
                int nc = c + dirs[i + 1];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col) {
                    if (!visited[nr][nc] && board[nr][nc] != 'X') {
                        visited[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

      
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        bfs(board, visited);
         for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};