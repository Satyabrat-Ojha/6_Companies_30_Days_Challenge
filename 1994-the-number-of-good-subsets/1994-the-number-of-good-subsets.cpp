#define ll long long
const ll MOD = 1e9+7;

class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        unordered_map<int,int> m;
        int ones = 0, res = 0;
        vector<int> temp, dp(1<<10), primes = {2,3,5,7,11,13,17,19,23,29};
        dp[0] = 1;

        for(auto num:nums) {
            if(num%4==0 || num%9==0 || num%25==0) continue;
            if(num==1) ones++;
            else m[num]++; 
        }

        for(auto e:m) {

            // find current mask
            int curr_mask = 0;
            for(int i=0;i<10;i++)
                if(e.first % primes[i] == 0)
                    curr_mask+=(1<<i);

            // state updates
            temp.assign(1<<10, 0);
            for(int mask=0; mask<(1<<10); mask++)
                if( (curr_mask & mask) ==0)
                    temp[mask | curr_mask] = ((ll) dp[mask]*(ll) e.second)%MOD;

            // add tmp to dp
            for(int i=0; i<(1<<10); i++)
                dp[i] = (dp[i]+temp[i]) % MOD;
        }

        // excule empty set
        for(int i=1;i<(1<<10);i++) res = (res + dp[i]) % MOD;

        // deal with ones
        while(ones--) {
            res = ((ll)res * 2LL) % MOD;
        }

        return res;
    }
};