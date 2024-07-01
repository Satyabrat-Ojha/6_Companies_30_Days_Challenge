class Node {
public:
    vector<Node*> child;
    int isEnd;
    Node() { child.assign(26, nullptr); isEnd = 0; }
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(auto w:word) {
            int i = w-'a';
            if(!node->child[i]) node->child[i] = new Node();
            node = node->child[i];
        }
        node->isEnd = 1;
    }

    bool search(string word) {
        return _search(word, root);
    }
    
private:
    bool _search(string word, Node* node) {
        if(!node) return 0;
        if(word.empty()) return node->isEnd;
        if(word[0] != '.') return _search(word.substr(1), node->child[word[0]-'a']);

        for(auto c : node->child)
            if(_search(word.substr(1), c)) return 1;

        return 0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */