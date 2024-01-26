class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        vector<vector<bool>> g(rows,vector<bool>(cols));

        queue<vector<int>> q;
        q.push({rCenter,cCenter});

        while(!q.empty()) {
            auto e = q.front();
            q.pop();
            
            if(!check(e[0],e[1],rows,cols) || g[e[0]][e[1]]) continue;
            
            ans.push_back(e);
            g[e[0]][e[1]]=1;

            q.push({e[0]+1,e[1]});
            q.push({e[0]-1,e[1]});
            q.push({e[0],e[1]+1});
            q.push({e[0],e[1]-1});
        }

        return ans;
    }

    bool check(int i, int j, int n, int m) {
        if(i<0 || j<0) return 0;
        if(i>=n || j>=m) return 0;
        return 1;
    }
};