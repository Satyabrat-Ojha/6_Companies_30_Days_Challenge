class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> st;
        for(auto word:dictionary) st.insert(word);
        int n = s.size();
        vector<int> dp(n+1);

        for(int i=1;i<=n;i++) {
            dp[i]=dp[i-1]+1;
            for(int j=i-1;j>=0;j--) {
                string t = s.substr(j,i-j);
                if(st.count(t)) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }

        return dp[n];
    }
};