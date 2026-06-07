struct TrieNode{
    public:
    vector<TrieNode*> child;
    bool end;

    TrieNode(){
        end = false;
        child.assign(26, nullptr);
    }
};

class Trie {
public:

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* child = root;
        for(char c: word){
            int idx = c-'a';
            if(child->child[idx] == nullptr){
                child->child[idx] = new TrieNode();
            }
             child = child->child[idx];
        }

        child->end = true;
    }
    
    bool search(string word) {
        TrieNode* child = root;
        for(char c: word){
            int idx = c-'a';
            if(child->child[idx] == nullptr) return false;
             child = child->child[idx];
        }
        if(child->end == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* child = root;
        for(char c: prefix){
            int idx = c-'a';
            if(child->child[idx] == nullptr) return false;
                child = child->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */