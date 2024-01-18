class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>dp(nums.size());

        int n = nums.size();

        for(int i=0;i<n;i++) dp[i].push_back(nums[i]);

        for(int i=0;i<n;i++) {
            int mx=0, it=-1;
            for(int j=0;j<i;j++) {
                if(nums[i]%nums[j]==0 && mx < dp[j].size()) {
                    mx = dp[j].size();
                    it = j;
                }
            }
            if(it!=-1) {
                dp[i] = dp[it];
                dp[i].push_back(nums[i]);
            }
        }

        int it=0;
        for(int i=0;i<nums.size();i++) {
            if(dp[it].size()<dp[i].size()) it=i;
        }

        return dp[it];
    }
};