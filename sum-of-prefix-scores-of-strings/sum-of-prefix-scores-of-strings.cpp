class Solution {
public:
    struct TrieNode {
    public:
       array<TrieNode*, 26> child;
        bool end;
        int words;

        TrieNode() {
            end = false;
            child.fill( nullptr);
            words = 0;
        }
    };

    class Trie {
    public:
        TrieNode* root;

        Trie() { root = new TrieNode(); }

        void insert(string word) {
            TrieNode* child = root;
            for (char c : word) {
                int idx = c - 'a';
                if (child->child[idx] == nullptr) {
                    child->child[idx] = new TrieNode();
                }
                child = child->child[idx];
                child->words++;
            }

            child->end = true;
        }

        bool search(string word) {
            TrieNode* child = root;
            for (char c : word) {
                int idx = c - 'a';
                if (child->child[idx] == nullptr)
                    return false;
                child = child->child[idx];
            }
            if (child->end == true)
                return true;
            return false;
        }

        int startsWith(string prefix) {
            TrieNode* child = root;
            int words = 0;
            for (char c : prefix) {
                int idx = c - 'a';
                child = child->child[idx];
                words += child->words;
            }
            return words;
        }
    };
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();
        for (string s : words) {
            trie->insert(s);
        }

        vector<int> arr;
        
        for (string s : words) {
            arr.push_back(trie->startsWith(s));
        }

        return arr;
    }
};