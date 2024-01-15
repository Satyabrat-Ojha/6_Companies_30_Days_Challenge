class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // to store all-pair-shortest-path
        vector<vector<long long>> sp(26,vector<long long>(26,1e11+2));
        
        for(int i=0;i<26;i++) sp[i][i]=0; 

        for(int i=0;i<cost.size();i++) {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            long long z = cost[i];

            sp[x][y] = min(sp[x][y], z);
        }

        // Floyd's Algorithm
        for(int k=0;k<26;k++) {
            for(int i=0;i<26;i++) {
                for(int j=0;j<26;j++) {
                    sp[i][j] = min(sp[i][j], sp[i][k] + sp[k][j]);
                }
            }
        }

        long long ans = 0;

        for(int i=0;i<source.size();i++) {
            int x = source[i] - 'a';
            int y = target[i] - 'a';
            long long z = sp[x][y];

            if(z == 1e11+2) return -1;
            ans += z;
        }

        return ans;
    }
};