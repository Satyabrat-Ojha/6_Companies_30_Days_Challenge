class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());
        vector<vector<int>> lower, upper;

        for(auto tree:trees) {
            while((lower.size()>=2) && (compare(lower[lower.size()-2], lower[lower.size()-1], tree) > 0))
                lower.pop_back();
            while((upper.size()>=2) && (compare(upper[upper.size()-2], upper[upper.size()-1], tree) < 0))
                upper.pop_back();

            lower.push_back(tree);
            upper.push_back(tree);
        }

        for(auto tree:lower) cout<<tree[0]<<" "<<tree[1]<<"\n";
        for(auto tree:upper) cout<<tree[0]<<" "<<tree[1]<<"\n";

        set<vector<int>> st;
        for(auto tree:lower) st.insert(tree);
        for(auto tree:upper) st.insert(tree);
        map<vector<int>,int> m;
        for(auto tree:trees) m[tree]++;

        vector<vector<int>> ans;
        for(auto e:st) {
            while(m[e]--) {
                ans.push_back(e);
            }
        }

        return ans;
    }

    int compare(vector<int> p1, vector<int> p2, vector<int> p3) {
        int x1 = p1[0], x2 = p2[0], x3 = p3[0];
        int y1 = p1[1], y2 = p2[1], y3 = p3[1];

        // m12 - m23
        // (y2 - y1)(x3 - x2) - (y3 - y2)(x2 - x1)

        return (y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1);
    }
};