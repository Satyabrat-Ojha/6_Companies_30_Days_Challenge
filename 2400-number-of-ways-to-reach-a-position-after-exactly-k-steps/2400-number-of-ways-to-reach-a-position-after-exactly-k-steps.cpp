class Solution {
public:
    const int MOD = 1e9+7;

    int numberOfWays(int startPos, int endPos, int k) {
        int diff = abs(startPos-endPos);
        if(diff > k || abs(diff-k)%2) return 0;
        
        int r = (k-diff)/2;

        return nCr(k,r);
    }

    int nCr(int n, int r) {
        if(r == 0) return 1;
        vector<int>v(r+1);
        v[0]++;
        for(int i=1;i<=n;i++) {
            for(int j=r;j>0;j--) {
                v[j] = (v[j] + v[j-1])%MOD; 
            }
        }
        return v[r];
    }
};