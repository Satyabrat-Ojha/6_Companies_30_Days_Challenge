class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<pair<int,bool>> v(1e5+1);
        for(auto e:matches) {
            int winner = e[0], loser = e[1];
            v[winner].second = v[loser].second = 1;
            v[loser].first++;
        }

        vector<vector<int>> ans(2);

        for(int i=1;i<v.size();i++) {
            if(v[i].second) {
                if(v[i].first == 0) ans[0].push_back(i);
                if(v[i].first == 1) ans[1].push_back(i);
            }
        }

        return ans;
    }
};