class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> dist(n, vector<int>(n,n));
        
        for(auto e:edges) 
            dist[e[0]-1][e[1]-1] = dist[e[1]-1][e[0]-1] = 1;

        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        vector<int> ans(n-1);
        for(int i=0;i<(1<<n);i++) {
            int d = maxDistance(i, dist, n);
            if(d > 0) ans[d-1]++;
        }

        return ans;
    }

    int maxDistance(int state, vector<vector<int>>& dist, int n) {
        int cntEdge = 0, cntCity = 0, maxDist = 0;

        for(int i=0;i<n;i++) {
            if((state & (1 << i)) == 0) continue;
            cntCity++;    
            for(int j=i+1;j<n;j++) {
                if((state & (1 << j)) == 0) continue;
                cntEdge += dist[i][j] == 1;
                maxDist = max(maxDist, dist[i][j]);
            }
        }

        if(cntEdge != cntCity - 1) return 0;

        return maxDist;
    }
};