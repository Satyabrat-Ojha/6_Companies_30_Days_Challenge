class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<vector<pair<string,int>>> v(101);

        for(int i=1;i<=100;i++) {
            for(int j=0;j<nums.size();j++) {
                int x = nums[j].size() - i;
                if(x<0) x=0;
                string s = nums[j].substr(x);
                v[i].push_back({s,j});
            }
            sort(v[i].begin(),v[i].end());
        }

        vector<int>ans;
        
        for(auto q:queries) {
            ans.push_back(v[q[1]][q[0]-1].second);
        }

        return ans;
    }
};