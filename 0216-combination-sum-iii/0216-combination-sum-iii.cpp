class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        vector<int>a;
        solve(a,0,k,n);
        return ans;
    }

    void solve(vector<int> &v, int c, int k, int n) {
        if(v.size()==k && n==0) ans.push_back(v);
        if(v.size()>=k) return;
        if(c==9) return;

        c++;
        solve(v,c,k,n);
        v.push_back(c);
        n-=c;
        solve(v,c,k,n);
        v.pop_back();
    }
};