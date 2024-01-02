class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> us;
        vector<int> pr(nums.size(),0);
        pr[0] = (bool)(nums[0]%p == 0);
        for(int i=1;i<nums.size();i++)
            pr[i] = pr[i-1] + (bool)(nums[i]%p == 0);

        for(int i=0;i<nums.size();i++) {
            vector<int>x;
            int m=0;
            if(i) m=pr[i-1];

            for(int j=i;j<nums.size();j++) {
                x.push_back(nums[j]);
                if(pr[j]-m <= k) {
                    us.insert(x);
                }
                else {
                    break;
                }
            }
        }

        return us.size();
    }
};