class Solution {
    int M,N,mx;
    unordered_set<int>v;
public:
    Solution(int m, int n) {
        M=m;
        N=n;
        mx=M*N;
    }
    
    vector<int> flip() {
        if(v.size()==mx) return {};
        int r = rand() % mx;
        while(v.count(r)) {
            r = (++r) % mx;
        }
        v.insert(r);
        return {r/N, r%N};
    }
    
    void reset() {
        v={};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */