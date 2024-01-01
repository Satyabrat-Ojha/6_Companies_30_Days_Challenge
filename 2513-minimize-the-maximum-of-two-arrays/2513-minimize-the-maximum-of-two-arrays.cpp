class Solution {
public:
    int minimizeSet(int d1, int d2, int u1, int u2) {
        long long low = 1, high = INT_MAX;

        while(low<=high) {
            long long mid = low + (high-low)/2;
            if(check(mid,d1,d2,u1,u2)) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }

    bool check(long long val, long long d1, long long d2, long long u1, long long u2) {
        long long div1 = val/d1, div2 = val/d2, div12 = val/lcm(d1,d2);

        if(val - div12 < u1 + u2) return 0;
        if(val - div1 < u1) return 0;
        if(val - div2 < u2) return 0;

        return 1;
    }
};