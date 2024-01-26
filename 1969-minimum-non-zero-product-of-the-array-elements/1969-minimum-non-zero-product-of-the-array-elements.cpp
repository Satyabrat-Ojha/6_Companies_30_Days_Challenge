class Solution {
    const int MOD = 1e9 + 7;
public:
    int minNonZeroProduct(int p) {
        long long N = pow(2,p);
        N--;
        long long A = N-1;
        long long B = N/2;
        long long M = exp(A,B);
        return ((N % MOD) * (M % MOD)) % MOD;
    }

    long long exp(long long A, long long B) {
        if(B==0) return 1;
        if(B==1) return A%MOD;

        long long C = exp(A,B/2) % MOD;
        C = (C*C)%MOD;

        if(B%2) return (C*(A%MOD))%MOD;
        else return C;
    }
};