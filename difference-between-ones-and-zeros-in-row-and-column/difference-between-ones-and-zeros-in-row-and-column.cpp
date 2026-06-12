class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();

        vector<int> rowCount(r);
        vector<int> colCount(c);

        for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if(grid[i][j] == 1){
                        rowCount[i]++;
                        colCount[j]++;
                    }
                }
        }

        vector<vector<int>> res(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    res[i][j] = rowCount[i] - (r - rowCount[i]) + colCount[j] - (c - colCount[j]);
                }
        }

        return res;
    }
};