class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0]; 
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> v;
        for(auto envelope:envelopes) v.push_back(envelope[1]);
        return LIS(v);
    }

    int LIS(vector<int>& v) {
        int i = v.size();
        vector<int> a;

        for(auto e:v) {
            int i = lower_bound(a.begin(),a.end(),e) - a.begin();
            if(i == a.size()) a.push_back(e);
            else a[i] = e;
        }

        return a.size();
    }
};