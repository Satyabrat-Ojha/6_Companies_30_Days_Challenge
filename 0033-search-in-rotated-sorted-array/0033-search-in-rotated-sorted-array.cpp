class Solution {
public:
    int search(vector<int>& nums, int target) {
        int m = findMin(nums), l, r;
        if(target <= nums.back()) { l = m; r = nums.size() - 1; }
        else { l = 0; r = m - 1; }

        while(l < r) {
            int mid = l+(r-l)/2;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }

        return (nums[l] == target) ? l : -1;
    }

    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l<r) {
            int mid = l+(r-l)/2;
            if(nums[r] < nums[mid]) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};