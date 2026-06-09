class Solution {
public:
    void dfs(int i, int j, int orgC, int color, vector<vector<int>>& image) {

        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != orgC) {
            return;
        }

        image[i][j] = -1;
        dfs(i - 1, j, orgC, color, image);
        dfs(i + 1, j, orgC, color, image);
        dfs(i, j - 1, orgC, color, image);
        dfs(i, j + 1, orgC, color, image);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
                                   dfs(sr, sc, image[sr][sc], color, image);  
                                   for(int i = 0; i < image.size(); i++){
                                    for(int j =0; j < image[0].size(); j++){
                                        if(image[i][j] == -1){
                                            image[i][j] = color;
                                        }
                                    }
                                   }
                                   return image;
                        
                                  }
};
