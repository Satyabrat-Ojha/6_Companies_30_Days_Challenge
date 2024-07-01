class Node {
public:
    vector<Node*> edges;
    bool isEnd;

    Node() {
        edges.assign(26, NULL);
        isEnd = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++) {
            if(!node->edges[word[i] - 'a'])
                node->edges[word[i] - 'a'] = new Node();
            node = node->edges[word[i] - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++) {
            if(node->edges[word[i] - 'a'] == NULL) 
                return false;
            node = node->edges[word[i] - 'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++) {
            if(node->edges[prefix[i] - 'a'] == NULL) 
                return false;
            node = node->edges[prefix[i] - 'a'];
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