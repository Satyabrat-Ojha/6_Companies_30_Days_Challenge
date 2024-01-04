class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n+1,1);
        dp[0] = 0;
        vector<long long> p(n+1);

        for(int i=1;i<=n;i++) {
            if(i-delay>=0) {
                dp[i] = (dp[i] + p[i-delay])%MOD;
            }
            if(i-forget>=0) {
                dp[i] = (dp[i] - p[i-forget] + MOD)%MOD;
            }
            p[i] = (dp[i]+p[i-1])%MOD;
        }

        return (dp[n] - dp[n - forget] + MOD) % MOD;
    }
};