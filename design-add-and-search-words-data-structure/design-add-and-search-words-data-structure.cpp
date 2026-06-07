struct TrieNode {
public:
    vector<TrieNode*> child;
    bool end;

    TrieNode() {
        end = false;
        child.assign(26, nullptr);
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
        }

        child->end = true;
    }

    bool search(string word, TrieNode* node) {
        if(word == "") return false;
        TrieNode* curr = node;

        for (int j = 0; j < word.size(); j++) {
            char c = word[j];

            if (c == '.') {
                
                for (int i = 0; i < 26; i++) {
                    if (curr->child[i] == nullptr)
                        continue;
                    // TrieNode* node = curr->child[i];
                    
                    string str = string(1, 'a' + i) + word.substr(j + 1);
                    if (search(str, curr)) {
                        return true;
                    }
                }
                return false;
            } else {
                int idx = c - 'a';
                if (curr->child[idx] == nullptr)
                    return false;
                curr = curr->child[idx];
            }
        }

        if (curr->end == true)
            return true;
        return false;
    }

};

class WordDictionary {
public:
    Trie* dic;
    WordDictionary() { dic = new Trie(); }

    void addWord(string word) { dic->insert(word); }

    bool search(string word) { return dic->search(word, dic->root); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */