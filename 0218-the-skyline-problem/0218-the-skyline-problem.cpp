class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int,int>> pq; // height,key
        vector<int> completed(buildings.size());
        sort(buildings.begin(),buildings.end());
        vector<pair<int,int>> v; // left&right,key
        for(int i=0;i<buildings.size();i++) {
            v.push_back({buildings[i][0], i});
            v.push_back({buildings[i][1], i});
        }
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        
        for(auto e : v) {
            int i = e.second;
            int h = buildings[i][2];
            if(!completed[i]) {
                pq.push({h,i});
            }
            completed[i]++;

            while(!pq.empty() && completed[pq.top().second] == 2) {
                pq.pop();
            }

            int x = e.first, y = 0;
            if(!pq.empty()) {
                y = pq.top().first;
            }

            if(ans.empty() || ans.back()[1] != y) {
                if(!ans.empty() && ans.back()[0] == x) ans.pop_back();
                if(ans.empty() || ans.back()[1] != y) ans.push_back({x,y});
            }
        }

        return ans;
    }
};