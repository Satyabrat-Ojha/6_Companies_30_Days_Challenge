class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto num:nums) {
            if(s.find(num) != s.end()) return 1;
            s.insert(num);
        }
        return 0;
    }
};