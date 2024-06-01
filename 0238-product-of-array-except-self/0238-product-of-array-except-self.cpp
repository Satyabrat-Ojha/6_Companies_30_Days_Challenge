class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zeros = 0;
        for(auto num:nums) {
            if(num) product *= num;
            else zeros++;
        }

        vector<int> ans;
        for(auto num:nums) {
            if(zeros > 1 || (zeros == 1 && num != 0)) ans.push_back(0);
            else if(zeros == 1) ans.push_back(product);
            else ans.push_back(product/num);
        }

        return ans;
    }
};