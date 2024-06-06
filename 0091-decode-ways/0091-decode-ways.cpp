class Solution {
    vector<int> dp;
public:
    int numDecodings(string s) {
        dp.assign(s.size()+1,-1);
        dp[0] = 1;
        return helper(s);
    }

    int helper(string s) {
        int i = s.size();
        if(dp[i] != -1) return dp[i];
        if(s[0] == '0') return dp[i] = 0;
        dp[i] = helper(s.substr(1));
        if(s.size() > 1) {
            string t = s.substr(0,2);
            if(t <= "26") dp[i] += helper(s.substr(2));
        }
        return dp[i];
    }
};