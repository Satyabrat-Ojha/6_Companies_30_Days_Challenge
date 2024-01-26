class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++) {
            v.push_back({aliceValues[i] + bobValues[i],i});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());

        int alice=0, bob=0;
        for(int i=0;i<n;i++) {
            int it = v[i].second;
            if(i%2) bob += bobValues[it];
            else alice += aliceValues[it];
        }

        if(alice > bob) return 1;
        else if(alice < bob) return -1;
        else return 0;
    }
};