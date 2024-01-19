class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k==0) {
            int ans = 0;
            map<int,int>m;
            for(auto e:nums) {
                if(m[e]==1) ans++;
                m[e]++;
            }
            return ans;
        }

        sort(nums.begin(),nums.end());
        vector<int>v;
        v.push_back(nums[0]);
        for(auto e:nums)
            if(e != v.back())
                v.push_back(e);
        
        int s = 1, e = 0, ans = 0;

        while(s<v.size()) {
            if(v[s]-v[e] == k) ans++;
            if(v[s]-v[e] > k) e++;
            else s++;

            if(s==e) s++;
        }
        return ans;
    }
};