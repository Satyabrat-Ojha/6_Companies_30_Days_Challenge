class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0, ans = 0, n = nums.size(), x = 0;
        for(int i=0;i<n;i++) sum += i*nums[i];
        ans = sum;
        for(int i=0;i<n;i++) x+=nums[i];

        for(int i=n-1;i>0;i--) {
            sum += x;
            sum -= n*nums[i];
            ans = max(ans,sum);
        }

        return ans;
    }
};