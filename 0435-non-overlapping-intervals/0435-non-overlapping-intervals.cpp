class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), last = intervals[0][1], ans = 0;
        for(int i=1;i<n;i++) {
            if(intervals[i][0] < last) {
                ans++;
                last = min(last, intervals[i][1]);
            }
            else last = intervals[i][1];
        }
        return ans;
    }
};