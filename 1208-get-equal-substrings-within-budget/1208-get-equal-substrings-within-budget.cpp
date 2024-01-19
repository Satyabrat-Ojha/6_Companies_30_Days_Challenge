class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int>v(1);
        for(int i=0;i<s.size();i++) v.push_back(abs(s[i]-t[i]));
        for(int i=1;i<v.size();i++) v[i]+=v[i-1];
        int S=1,e=0,l=0;
        while(S<v.size()) {
            if(v[S]-v[e] <= maxCost) {
                l = max(l,S-e);
                S++;
            }
            else e++;
            if(S==e) S++;
        }
        return l;
    }
};