class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(dfs(i, j, word, board))
                    return true;
        return false;
    }

    bool dfs(int i, int j, string word, vector<vector<char>>& board) {
        if(word.size() == 0) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return false;
        if(board[i][j] != word[0]) return false;
        
        char c = board[i][j];
        board[i][j] = ' ';

        bool flag = false;
        if(dfs(i+1, j, word.substr(1), board)) flag = true;
        else if(dfs(i, j+1, word.substr(1), board)) flag = true;
        else if(dfs(i-1, j, word.substr(1), board)) flag = true;
        else if(dfs(i, j-1, word.substr(1), board)) flag = true;

        board[i][j] = c;

        return flag;
    }
};