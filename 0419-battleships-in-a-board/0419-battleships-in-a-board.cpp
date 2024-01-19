class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        int n = board.size(), m = board[0].size();

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]=='X') {
                    ans++;
                    dfs(i,j,board);
                }
            }
        }

        return ans;
    }

    void dfs(int i,int j, vector<vector<char>>& board) {
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return;
        if(board[i][j]=='.') return;
        board[i][j]='.';
        dfs(i+1,j,board);
        dfs(i,j+1,board);
        dfs(i-1,j,board);
        dfs(i,j-1,board);
    }
};