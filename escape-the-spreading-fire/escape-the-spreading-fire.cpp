/*
 * @lc app=leetcode id=2258 lang=cpp
 *
 * [2258] Escape the Spreading Fire
 */

// @lc code=start
class Solution {
public:
    bool reached = false;
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& timeGrid,
             int time) {

        queue<vector<int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j, 0});
                }
            }
        }

        while (!q.empty()) {
            vector<int> arr = q.front();
            q.pop();
            int i = arr[0];
            int j = arr[1];
            int t = arr[2];
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
                continue;
            }
            if (grid[i][j] == 2) {
                timeGrid[i][j] = -1;
                continue;
            }
            if (timeGrid[i][j] >= 0 && timeGrid[i][j] < 1e9)
                continue;
            timeGrid[i][j] = t;
            q.push({i + 1, j, t + 1});
            q.push({i - 1, j, t + 1});
            q.push({i, j - 1, t + 1});
            q.push({i, j + 1, t + 1});
        }

        // for (int i = 0; i < timeGrid.size(); i++) {
        //     for (int j = 0; j < timeGrid[0].size(); j++) {
        //         cout << timeGrid[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }

   
      // 1D Direction Array trick (Up, Right, Down, Left)
int dirs[5] = {-1, 0, 1, 0, -1};

bool gridBFS(vector<vector<int>>& grid,vector<vector<int>>& timeGrid,  int startR, int startC, int wait) {
    int ROWS = grid.size();
    int COLS = grid[0].size();
    if(wait >= timeGrid[startR][startC]) return false;
    queue<vector<int>> q;
    vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

    q.push({startR, startC, wait});
    visited[startR][startC] = true;

    while (!q.empty()) {
        vector<int> arr= q.front();
        int r = arr[0], c= arr[1], t = arr[2];
        q.pop();
        if(r == (ROWS -1 )&& c== (COLS-1) &&  (timeGrid[r][c] >= t || timeGrid[r][c]==0)) return true;
        for (int i = 0; i < 4; i++) {
            // i=0: (-1, 0) -> Up
            // i=1: ( 0, 1) -> Right
            // i=2: ( 1, 0) -> Down
            // i=3: ( 0,-1) -> Left
            int nr = r + dirs[i];
            int nc = c + dirs[i + 1];

            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS) {
                if (!visited[nr][nc] && grid[nr][nc] != 2 && (timeGrid[nr][nc] > t+1 || (nr == (ROWS -1) && nc== (COLS-1)))) {
                    visited[nr][nc] = true;
                    q.push({nr, nc, t+1});
                }
            }
        }
    }

    return false;
}

    int maximumMinutes(vector<vector<int>>& grid) {
        vector<vector<int>> timeGrid(grid.size(), vector<int>(grid[0].size(), 2e9));

        int time = 0;
        int fDiff = -1;
        bfs(grid, timeGrid, time);

        int start = 0;
        int end = 1e9;
        int ans =-1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(gridBFS(grid, timeGrid, 0,0,mid )){
                ans = mid;
                start = mid +1;
            }else{
                end = mid -1;
            }
        }

        // dfs(0, 0, timeGrid, grid, 0, INT_MAX, fDiff);
        // if(reached == false) return -1;
        // if(fDiff == INT_MAX) return 1e9;
        return ans;
    }
};
// @lc code=end
