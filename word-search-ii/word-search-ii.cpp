class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> child;
        string word;

        TrieNode() {
            child.assign(26, nullptr);
            word = "";
        }
    };

    class Trie {
    public:
        TrieNode* root;

        Trie() { root = new TrieNode(); }

        void insert(string word) {
            TrieNode* curr = root;

            for (char c : word) {
                int idx = c - 'a';

                if (curr->child[idx] == nullptr)
                    curr->child[idx] = new TrieNode();

                curr = curr->child[idx];
            }

            curr->word = word;
        }

    };

    void dfs(int i, int j, Trie& trie, TrieNode* node, vector<vector<char>>& board, 
             vector<string>& res, vector<string>& words) {

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] == '^')
            return;

        int idx = board[i][j] - 'a';
        if (node->child[idx] == nullptr)
            return;
        node = node->child[idx];
        if (node->word != "" ) {
            res.push_back(node->word);
            node->word = "";
        }
        board[i][j] = '^';
        dfs(i - 1, j, trie, node, board,  res, words);
        dfs(i + 1, j, trie, node, board,  res, words);
        dfs(i, j - 1, trie, node, board,  res, words);
        dfs(i, j + 1, trie, node, board,  res, words);
        board[i][j] = idx + 'a';
        return;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        Trie trie;
        for (auto& s : words)
            trie.insert(s);

        string str = "";
        vector<string> res;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                dfs(i, j, trie,trie.root, board, res, words);
            }
        }

        return res;
    }
};