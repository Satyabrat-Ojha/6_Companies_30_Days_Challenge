class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() {
        isWord = 0;
        for(auto &c:child) c = nullptr;
    }
};

class WordDictionary {
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        auto t = root;
        for(auto c:word) {
            int i = c - 'a';
            if(!t->child[i]) t->child[i] = new TrieNode();
            t = t->child[i];
        }
        t->isWord = 1;
    }
    
    bool search(string word) {
        return searchH(word,root);
    }

    bool searchH(string word, TrieNode* t) {
        if(word.empty()) return t->isWord;

        if(word[0] != '.') {
            int i = word[0] - 'a';
            if(!t->child[i]) return 0;
            return searchH(word.substr(1), t->child[i]);
        }

        for(int i=0;i<26;i++)
            if(t->child[i] && searchH(word.substr(1), t->child[i]))
                return 1;

        return 0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */