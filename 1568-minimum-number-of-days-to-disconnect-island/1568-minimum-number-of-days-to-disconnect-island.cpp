class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        if(!isConnected(grid)) return 0;
        if(countOnes(grid) < 3) return countOnes(grid);

        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]) {
                    grid[i][j]=0;
                    if(!isConnected(grid)) return 1;
                    grid[i][j]=1;
                }
            }
        }

        return 2;
    }

    bool isConnected(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        bool flag=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]) {
                    flag=1;
                    dfs(i,j,n,m,grid);
                    break;
                }
            }
            if(flag) break;
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1)
                    return 0;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==2)
                    grid[i][j]=1;

        return 1;
    }

    void dfs(int i,int j,int n,int m, vector<vector<int>>& grid) {
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(grid[i][j]!=1) return;

        grid[i][j]=2;
        dfs(i+1,j,n,m,grid);
        dfs(i,j+1,n,m,grid);
        dfs(i-1,j,n,m,grid);
        dfs(i,j-1,n,m,grid);
    }

    int countOnes(vector<vector<int>>& grid) {
        int c = 0, n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                c+=grid[i][j];
        return c;
    }
};