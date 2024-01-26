class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& r) {
        int ans = abs(start[0] - target[0]) + abs(start[1] - target[1]);
        int n = r.size();
        vector<int> dp(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++) {
            dp[i] = abs(start[0] - r[i][0]) + abs(start[1] - r[i][1]) + r[i][4];
            pq.push({dp[i],i});
        }

        while(!pq.empty()) {
            auto [dist, i] = pq.top();
            pq.pop();

            if(dist != dp[i]) continue;

            ans = min(ans, dist + abs(target[0] - r[i][2]) + abs(target[1] - r[i][3]));

            for(int j=0;j<n;j++) {
                int w = abs(r[i][2] - r[j][0]) + abs(r[i][3] - r[j][1]) + r[j][4];
                if(w + dist < dp[j]) {
                    dp[j] = w + dist;
                    pq.push({dp[j],j});
                }
            }
        }

        return ans;
    }
};