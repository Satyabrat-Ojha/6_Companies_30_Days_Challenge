class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int e=-1,ans=0;
        for(int i=0;i<nums.size();i++) {
            m[nums[i]]++;
            while(m[nums[i]]>k) {
                e++;
                m[nums[e]]--;
            }
            ans = max(ans, i - e);
        }
        return ans;
    }
};