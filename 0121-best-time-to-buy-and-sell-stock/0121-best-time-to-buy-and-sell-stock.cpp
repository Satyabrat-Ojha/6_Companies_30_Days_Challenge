class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices[0], ans = 0;
        for(auto price:prices) {
            m = min(m, price);
            ans = max(ans, price - m);
        }
        return ans;
    }
};