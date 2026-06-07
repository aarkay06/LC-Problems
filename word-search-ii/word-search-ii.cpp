class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> child;
        bool end;

        TrieNode() {
            child.assign(26, nullptr);
            end = false;
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

            curr->end = true;
        }

        bool search(string word) {
            TrieNode* curr = root;

            for (char c : word) {
                int idx = c - 'a';

                if (curr->child[idx] == nullptr)
                    return false;

                curr = curr->child[idx];
            }

            if( !curr->end) return false;
            curr->end=false;
            return true;
        }

        bool startsWith(string prefix) {
            TrieNode* curr = root;

            for (char c : prefix) {
                int idx = c - 'a';

                if (curr->child[idx] == nullptr)
                    return false;

                curr = curr->child[idx];
            }

            return true;
        }
    };

    void bfs(int i, int j, Trie& trie, vector<vector<char>>& board, string str,
             vector<string>& res, vector<string>& words) {

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] == '^')
            return;

        str += board[i][j];
        char a = board[i][j];
        bool okay = false;
        if(!trie.startsWith(str)) return;
        if(trie.search(str)) res.push_back(str);

        board[i][j] = '^';
        bfs(i - 1, j, trie, board, str, res, words);
        bfs(i + 1, j, trie, board, str, res, words);
        bfs(i, j - 1, trie, board, str, res, words);
        bfs(i, j + 1, trie, board, str, res, words);
        board[i][j] = a;
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
                bfs(i, j, trie, board, str, res, words);
            }
        }

        return res;
    }
};