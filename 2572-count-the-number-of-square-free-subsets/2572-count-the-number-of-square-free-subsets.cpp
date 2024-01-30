#define ll long long

class Solution {
    const ll MOD = 1e9 + 7;
    ll dp[1111][1<<11];
    vector<int> primes;

public:
    int squareFreeSubsets(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        primes = {2,3,5,7,11,13,17,19,23,29};
        return (dfs(0,1,nums) - 1 + MOD) % MOD;
    }

    ll dfs(int idx, ll product, vector<int>& nums) {
        if(idx >= nums.size()) return 1;
        if(dp[idx][product] != -1) return dp[idx][product];

        ll mask = getMask(nums[idx]);
        ll ans = dfs(idx + 1, product, nums);

        if((product & mask) == 0) {
            ans = (ans + dfs(idx + 1, product | mask, nums)) % MOD;
        }

        return dp[idx][product] = ans;
    }

    ll getMask(ll num) {
        ll mask = 0;

        for(int i=0;i<10;i++) {
            int count = 0;
            while(num % primes[i] == 0) {
                count++;
                num /= primes[i];
            }
            if(count > 1) return -1;
            if(count == 1) mask |= (1 << (i+1));
        }

        return mask;
    }
};