class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>>v(255);
        for(int i=0;i<255;i++) v[i] = {0,(char)i};
        for(char c:s) v[c].first++;
        sort(v.begin(),v.end(),cmp);
        s="";
        for(auto e:v) {
            while(e.first--) {
                s+=e.second;
            }
        }
        return s;
    }

    static bool cmp(pair<int,char>p1,pair<int,char>p2) {
        if(p1.first == p2.first) return (p1.second < p2.second);
        return (p1.first > p2.first);
    }
};