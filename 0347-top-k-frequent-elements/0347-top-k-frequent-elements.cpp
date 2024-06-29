class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(auto num:nums) m[num]++;
        vector<vector<int>> bucket(n+1);
        for(auto [key,val]:m) bucket[val].push_back(key);
        vector<int> ans;
        for(int i=n;i>=0 && ans.size()<k;i--) {
            while(!bucket.back().empty()) {
                ans.push_back(bucket.back().back());
                bucket.back().pop_back();
            }
            bucket.pop_back();
        }
        return ans;
    }
};