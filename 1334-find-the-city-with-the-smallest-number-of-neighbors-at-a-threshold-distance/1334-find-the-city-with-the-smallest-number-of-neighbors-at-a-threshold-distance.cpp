class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> v(n,vector<int>(n,1e9 + 7));

        for(auto e:edges) {
            v[e[0]][e[1]] = e[2];
            v[e[1]][e[0]] = e[2];
        }

        for(int i=0;i<n;i++) {
            v[i][i]=0;
        }
        
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                }
            }
        }

        int it = 0, m = n+1;

        for(int i=0;i<n;i++) {
            int c=0;
            for(int j=0;j<n;j++) {
                if(v[i][j]<=distanceThreshold) {
                    c++;
                }
            }

            if(c<=m) {
                m=c;
                it = i;
            }
        }

        return it;
    }
};