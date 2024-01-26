class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        if(!right.empty())
            ans = n - *min_element(right.begin(),right.end());
        if(!left.empty())
            ans = max(ans, *max_element(left.begin(),left.end()));

        return ans;
    }
};