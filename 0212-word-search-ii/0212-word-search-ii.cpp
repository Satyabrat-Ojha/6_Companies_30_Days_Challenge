class Node {
public:
    vector<Node*> child;
    bool isWord;
    Node() { child.assign(26, nullptr); isWord = 0; }
};

class Solution {
    vector<string> ans;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        for(auto word:words) insert(word, root);
        ans.clear();
        string s="";
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                dfs(i,j,s,root,board);
        return ans;
    }

    void insert(string word, Node* node) {
        for(auto c:word) {
            if(!node->child[c-'a']) node->child[c-'a'] = new Node();
            node = node->child[c-'a'];
        }
        node->isWord = 1;
    }

    void dfs(int i, int j, string& s, Node* node, vector<vector<char>>& board) {
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='#') return;
        
        char c = board[i][j];
        if(!node->child[c-'a']) return;
        board[i][j] = '#';
        
        s.push_back(c);
        node = node->child[c-'a'];

        if(node->isWord) {
            ans.push_back(s);
            node->isWord = 0;
        }

        dfs(i+1, j, s, node, board);
        dfs(i, j+1, s, node, board);
        dfs(i-1, j, s, node, board);
        dfs(i, j-1, s, node, board);

        board[i][j] = c;
        s.pop_back();
    }
};