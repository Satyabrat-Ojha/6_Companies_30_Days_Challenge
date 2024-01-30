class Solution {
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
public:
    int specialPerm(vector<int>& nums) {
        dp.resize(20, vector<int>((1 << 14) + 5, -1));
        return solve(nums, -1, 0, 0);
    }

    int solve(vector<int>& nums, int prevIdx, int currIdx, int mask) {
        if(currIdx == nums.size()) return 1;
        if(dp[prevIdx + 1][mask] != -1) return dp[prevIdx+1][mask];

        int total = 0;
        for(int i=0;i<nums.size();i++) {
            if(mask & (1<<i)) continue;
            if(prevIdx == -1 || nums[prevIdx] % nums[i] == 0 || nums[i] % nums[prevIdx] == 0) {
                total += solve(nums, i, currIdx + 1, mask | (1 << i));
                total %= MOD;
            }
        }

        return dp[prevIdx + 1][mask] = total;
    }
};