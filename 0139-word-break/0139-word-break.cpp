class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n);
        unordered_set<string> st;
        for(auto word:wordDict) st.insert(word);

        for(int i=0;i<n;i++) {
            if(i!=0 && dp[i-1]==0) continue;
            for(int j=1;i+j-1<n;j++)
                if(st.find(s.substr(i,j)) != st.end())
                    dp[i+j-1] = 1;
        }

        return dp[n-1];
    }
};