class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m = mass;
        sort(asteroids.begin(),asteroids.end());
        for(auto a:asteroids) {
            if(a>m) return 0;
            else m+=a;
        }
        return 1;
    }
};