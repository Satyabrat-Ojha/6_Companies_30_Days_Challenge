class Solution {
    vector<vector<int>> rectangles;
    vector<int> prefix;
    int SIZE;

public:
    Solution(vector<vector<int>>& rects) {
        rectangles = rects;
        for(int i=0;i<rects.size();i++) {
            int space = (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
            if(i==0) prefix.push_back(space);
            else prefix.push_back(prefix[i-1] + space);
        }
        SIZE = prefix.back();
    }
    
    vector<int> pick() {
        int R = rand() % SIZE;
        int i = upper_bound(prefix.begin(),prefix.end(), R) - prefix.begin();
        int L = rectangles[i][2] - rectangles[i][0] + 1;
        int B = rectangles[i][3] - rectangles[i][1] + 1;
        int I = rand()%L, J = rand()%B; 
        I += rectangles[i][0];
        J += rectangles[i][1];

        return {I,J};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */