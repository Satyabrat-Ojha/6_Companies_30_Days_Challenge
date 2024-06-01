class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, curp = 1, curn = 1;
        for(auto num:nums) {
            ans = max(ans, num);
            if(num == 0) {curp = curn = 1; continue;}
            curp *= num;
            curn *= num;
            ans = max({ans, curp, curn});
            int p = 1, n = 1;
            if(curp < 1) { n = curp; curp = 1; }
            if(curn > 1) { p = curn; curn = 1; }
            curp = max(p, curp);
            curn = min(n, curn);
        }
        return ans;
    }
};