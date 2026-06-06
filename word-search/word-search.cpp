class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board, int index,
             string& word) {

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] == '^' || board[i][j] != word[index])
            return false;

        char a = board[i][j];

        if (index == word.size() - 1)
            return true;
        board[i][j] = '^';
        if (dfs(i - 1, j, board, index + 1, word) ||
            dfs(i + 1, j, board, index + 1, word) ||
            dfs(i, j - 1, board, index + 1, word) ||
            dfs(i, j + 1, board, index + 1, word))
            return true;

        board[i][j] = a;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, board, 0, word))
                        return true;
                }
            }
        }
        return false;
    }
};