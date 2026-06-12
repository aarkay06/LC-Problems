class Solution {
public:

    struct TrieNode{
    public:
    array<TrieNode*, 26> child;
    bool end;

    TrieNode(){
        end = false;
        child.fill( nullptr);
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
    
    string rootWord(string prefix) {
        TrieNode* child = root;

        string str = "";
        for(char c: prefix){
            int idx = c-'a';
            if(child->child[idx] == nullptr) return prefix;
                child = child->child[idx];
                str += c;
               
                if(child->end == true) return str;
        }
        return str;
    }
};

    string replaceWords(vector<string>& dict, string sentence) {
        Trie* trie = new Trie();
        for(string s:dict ){
            trie->insert(s);
        }

        vector<string> arr;
        string word = "";
        for(int i=0; i<sentence.size(); i++){
            if(sentence[i] == ' ') {
                arr.push_back(word);
                word = "";
            }
            else{
                word += sentence[i];
            }
        }

        arr.push_back(word);
        word = "";

        for(int i=0; i<arr.size(); i++){
            arr[i] = trie->rootWord(arr[i]);
            word += arr[i];
            if(i != arr.size() -1) word+= ' ';
        }

        return word;

    }

};