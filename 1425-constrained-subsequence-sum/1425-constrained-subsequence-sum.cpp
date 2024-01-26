class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp = nums;
        priority_queue<pair<int,int>> pq;
        int n = nums.size();
        int ans = INT_MIN;

        for(int i=0;i<n;i++) {
            while(!pq.empty() && (i - pq.top().second)>k)
                pq.pop();

            if(!pq.empty())
                dp[i] += max(0, pq.top().first);

            ans = max(ans,dp[i]);
            pq.push({dp[i],i});
        }

        return ans;
    }
};