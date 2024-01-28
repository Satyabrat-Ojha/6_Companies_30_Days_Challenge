class Node {
public:
    Node *child[26];
    bool isWord;
    Node() {
        for(auto &c:child) c=nullptr;
        isWord=0;
    }
};

class Solution {
public:
    Node* root;
    vector<bool> dp;

    bool wordBreak(string s, vector<string>& wordDict) {
        insertDict(wordDict);
        dp.clear();
        dp.resize(s.size() + 1, 0);
        return findWord(s,root);
    }

    bool findWord(string s, Node* tail) {
        if(s.empty()) return tail->isWord;
        if(root == tail && dp[s.size()] == 1) return 0;

        if(tail->isWord && findWord(s,root)) return 1;

        int i = s[0] - 'a';
        if(tail->child[i] && findWord(s.substr(1), tail->child[i])) return 1;

        if(root == tail) dp[s.size()] = 1;
        return 0;
    }

    void insertDict(vector<string>& wordDict) {
        root = new Node();
        for(auto word:wordDict) {
            auto tail = root;
            for(auto c:word) {
                int i = c - 'a';
                if(!tail->child[i]) tail->child[i] = new Node();
                tail = tail->child[i];
            }
            tail->isWord = 1;
        }
    }
};