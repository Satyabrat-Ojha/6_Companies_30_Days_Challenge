class Solution {
public:
    int dp[13][13];
    string S,s1;
    int ans;

    int maxProduct(string s) {
        S = s1 = "";
        ans = 0;
        produce(s,S,s1,0);
        return ans;
    }

    void produce(string& s, string& S, string& s1, int i) {
        if(i>=s.size()) {
            if(check(S)) {
                find(S.size(),s1);
            }
            return;
        }
        string t = S;
        t+=s[i];
        produce(s,t,s1,i+1);
        t=s1;
        t+=s[i];
        produce(s,S,t,i+1);
    }

    bool check(string& s) {
        int n = s.size();
        for(int i=0;i<n/2;i++)
            if(s[i] != s[n-1-i]) return false;
        return true;
    }

    void find(int a, string& s) {
        memset(dp,-1,sizeof(dp));
        string s2 = s; 
        reverse(s2.begin(),s2.end());
        int lps = longest(s,s2,s.size(),s2.size());
        ans = max(ans,lps*a);
    }

    int longest(string& s1, string& s2, int n1, int n2) {
        if(!n1 || !n2) return 0;
        if(dp[n1][n2]!=-1) return dp[n1][n2];

        if(s1[n1-1]==s2[n2-1]) return dp[n1][n2]=1+longest(s1,s2,n1-1,n2-1);
        else return dp[n1][n2] = max(longest(s1,s2,n1-1,n2),longest(s1,s2,n1,n2-1));
    }
};