class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int N = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto num:nums) pq.push(num);

        while(k--) {
            int x = pq.top() + 1;
            pq.pop();
            pq.push(x);
        }

        long long ans = 1;
        while(!pq.empty()) {
            ans = ans * pq.top();
            ans %= N;
            pq.pop();
        }
        return ans;
    }
};