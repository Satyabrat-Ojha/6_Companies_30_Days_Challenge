class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++) {
            v.push_back({nums[i],i});
        }

        sort(v.begin(),v.end(),greater<pair<int,int>>());
        while(v.size()>k) v.pop_back();
        sort(v.begin(),v.end(),cmp);

        vector<int>ans;
        for(auto e:v) ans.push_back(e.first);
        return ans;
    }

    static bool cmp(pair<int,int>p1,pair<int,int>p2) {
        return p1.second<p2.second;
    }
};