class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int ans = 0;
        for(int i=0;i<ages.size();i++) {
            int x = ages[i];
            int y = ages[i]/2 + 7;
            int xi = upper_bound(ages.begin(),ages.end(),x) - ages.begin();
            int yi = upper_bound(ages.begin(),ages.end(),y) - ages.begin();
            if(yi>=xi) continue;
            ans += xi - yi - 1;
        }
        return ans;
    }
};