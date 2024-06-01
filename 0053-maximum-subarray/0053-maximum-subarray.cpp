class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0, curr = 0;
        for(auto num:nums) {
            curr += num;
            if(curr < 0) curr = 0;
            ans = max(ans,curr);
        }   
        
        if(ans == 0) ans = *max_element(nums.begin(),nums.end());

        return ans;
    }
};