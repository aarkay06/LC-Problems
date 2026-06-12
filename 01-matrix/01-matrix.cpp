class Solution {
public:
    int dirs[5] = {-1, 0, 1, 0, -1};

    void bfs(vector<vector<int>>& mat, vector<vector<int>>& visited) {
        int ROWS = mat.size();
        int COLS = mat[0].size();


        queue<vector<int>> q;
       
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j, 0});
                    visited[i][j] = 0;
                }
            }
        }


        while (!q.empty()) {
            vector<int> arr = q.front();
            int r = arr[0], c = arr[1], t = arr[2];
            q.pop();

            for (int i = 0; i < 4; i++) {
                // i=0: (-1, 0) -> Up
                // i=1: ( 0, 1) -> Right
                // i=2: ( 1, 0) -> Down
                // i=3: ( 0,-1) -> Left
                int nr = r + dirs[i];
                int nc = c + dirs[i + 1];

                if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS) {
                    if (!visited[nr][nc] && mat[nr][nc] != 0) {
                        visited[nr][nc] = t+1;
                        q.push({nr, nc, t + 1});
                    }
                }
            }
        }

    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size(), 0));
        bfs(mat, visited);
        return visited;
    }
};