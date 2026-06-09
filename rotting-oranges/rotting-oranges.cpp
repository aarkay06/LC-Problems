class Solution {
public:
    void bfs(vector<vector<int>>& grid, int & time) {
        queue<vector<int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
            }
        }

        while(!q.empty()){
            vector<int> arr= q.front();
            int i = arr[0];
            int j = arr[1];
            int t = arr[2];
            q.pop();
            if(i < 0 || i >= grid.size() ||  j < 0 || j >= grid[0].size() || grid[i][j] == 0) continue; 
            grid[i][j] = 0;
            time = max(t, time);
            q.push({i-1, j, t+1});
            q.push({i+1, j, t+1});
            q.push({i, j-1, t+1});
            q.push({i, j+1, t+1});
         }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        bfs(grid, time);
         for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                   return -1;
                }
            }
        }
        return time;
    }
};