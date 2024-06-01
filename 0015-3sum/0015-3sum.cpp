class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        int n = nums.size();

        for(int i=0;i<n-2;i++) {
            int sum = -nums[i];
            int l = i+1, r = n-1;
            while(l < r) {
                if(nums[l] + nums[r] < sum) l++;
                else if(nums[l] + nums[r] > sum) r--;
                else {
                    s.insert({nums[i], nums[l], nums[r]});
                    l++;
                }
            }
        }

        vector<vector<int>> ans;
        for(auto v:s) ans.push_back(v);
        return ans;
    }
};