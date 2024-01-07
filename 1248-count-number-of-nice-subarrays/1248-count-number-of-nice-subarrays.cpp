class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> v = {1};
        for(int num:nums) {
            if(num%2) v.push_back(1);
            else v.back()++;
        }
        
        int sum = 0;
        for(int i=k;i<v.size();i++) {
            sum += v[i]*v[i-k];
        }
        return sum;
    }
};