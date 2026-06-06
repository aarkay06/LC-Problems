class Solution {
public:
   void bfs(int i, int j,vector<vector<char>>& grid){
        if(i < 0 || i >= grid.size() || j < 0 || j>= grid[0].size() || grid[i][j] == '0') 
        return;

        grid[i][j] = '0';

        bfs(i-1, j, grid);
        bfs(i+1, j, grid);
        bfs(i, j-1, grid);
        bfs(i, j+1, grid);
        
   }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    bfs(i, j, grid);
                    count++;
                }
            }
        }

        return count;
    }
};