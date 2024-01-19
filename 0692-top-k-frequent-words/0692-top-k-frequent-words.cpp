class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        sort(words.begin(),words.end());
        vector<pair<int,string>> v;
        for(auto s:words) {
            if(v.empty() || s != v.back().second) v.push_back({1,s});
            else v.back().first++;
        }
        sort(v.begin(),v.end(),cmp);
        vector<string>ans;
        for(int i=0;i<k;i++) ans.push_back(v[i].second);
        return ans;
    }

    static bool cmp(pair<int,string>p1,pair<int,string>p2) {
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first > p2.first;
    }
};