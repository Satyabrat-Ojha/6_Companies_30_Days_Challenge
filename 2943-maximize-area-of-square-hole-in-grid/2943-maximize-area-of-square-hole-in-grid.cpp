class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int a = min(solve(hBars), solve(vBars));
        return a*a;
    }

    int solve(vector<int>& v) {
        sort(v.begin(),v.end());
        if(v.empty()) return 1;
        int ans = 2, c = 2;
        for(int i=1;i<v.size();i++) {
            if(v[i] == 1 + v[i-1]) c++;
            else c = 2;
            ans = max(ans,c);
        }
        return ans;
    }
};